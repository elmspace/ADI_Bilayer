/*
  In this function, we will be calculating the free energy
*/
void calculateFreeEnergy( ){

  int i,j,ii,jj,iter;

  Volume=0.0;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      dum_func1[i][j]=1.0;
    }
  }
  Volume=2.0*Pi*integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');  
  //Volume=Pi*(drz[1]*(NBox-1))*(((R+(drz[0]*(NBox-1)))*(R+(drz[0]*(NBox-1))))-(R*R));

  // Full area from center to right efge of box
  if(Pore==1){Area=Pi*(R+(drz[0]*NBox/2.0))*(R+(drz[0]*NBox/2.0));}
  if(Disk==1){Area=Pi*(R+(drz[0]*NBox/2.0))*(R+(drz[0]*NBox/2.0));}
  if(Bilayer==1){Area=Pi*(R+(drz[0]*NBox))*(R+(drz[0]*NBox));}
  

  // Setting the const chemical potential
  act_h=exp(kappa_homopolymer*(mu_h-mu_ref));
  act_t=exp(kappa_triblock*(mu_t-mu_ref));
  act_d=exp(kappa_diblock*(mu_d-mu_ref));
  
  // Homogenous free energy
  Homogenous_fE=calculatedHomogenousEnergy();

  iter=0;
  do{
 
    // Solving diffusion equations________________
    solveDiffusionEquation(0);
    solveDiffusionEquation(1);
    solveDiffusionEquation(2);  
    // Calculate SCFT Equations___________________
    calculatePhi();
    calculateEta();
    calculateOmega(); 
    // Calculate Free Energy______________________

    if(Canonical==1){
      Entropy_fE=((phiAve[0]/kappa_triblock)*log(Q_ABC))+((phiAve[1]/kappa_diblock)*log(Q_DE))+((phiAve[2]/kappa_homopolymer)*log(Q_F));
    }else if(GrandCanonical==1){
      Entropy_fE=(act_t*Q_ABC/kappa_triblock)+(act_d*Q_DE/kappa_diblock)+(act_h*Q_F/kappa_homopolymer);
    }

    Omega_fE=0.0;
    Interaction_fE=0.0;

    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	dum_func1[i][j]=0.0;
	dum_func2[i][j]=0.0;
	for(ii=0;ii<ChainType;ii++){
	  for(jj=0;jj<ChainType;jj++){
	    dum_func1[i][j]+=phi[ii][i][j]*chiMatrix[ii][jj]*phi[jj][i][j];
	  }
	  dum_func2[i][j]+=w[ii][i][j]*phi[ii][i][j];
	}
      }
    }
    Interaction_fE=integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c')/2.0;// 2 is for double counting
    Omega_fE=integrationTrapezoidal(dum_func2,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
        
    //Omega_fE*=((2.0*Pi)/Volume);
    //Interaction_fE*=((2.0*Pi)/Volume);
    Omega_fE*=(2.0*Pi);
    Interaction_fE*=(2.0*Pi);
    
    //totalFreeEnergy=Interaction_fE-Omega_fE-Entropy_fE-(Homogenous_fE*Volume);
    totalFreeEnergy=Interaction_fE-Omega_fE-Entropy_fE;
    
    //std::cout<<iter<<" "<<totalFreeEnergy<<"   "<<delta_W<<"  Phi_tri_ave="<<(p_ave[0]+p_ave[1]+p_ave[2])<<"  Phi_di_ave="<<(p_ave[3]+p_ave[4])<<"  Phi_hom_ave="<<p_ave[5]<<std::endl;
    std::cout<<iter<<" "<<delta_W<<" "<<(totalFreeEnergy/Volume)-Homogenous_fE<<" "<<(p_ave[0]+p_ave[1]+p_ave[2])<<" "<<(p_ave[3]+p_ave[4])<<" "<<p_ave[5]<<std::endl;
    
  
    saveData();
    iter++;
  }while((delta_W>precision)||(iter<500));

  
};











    /*
    if(iter>600 && iter<800){
      pin_cond = 1.0;
      for(i=0;i<NBox/2;i++){
	for(j=0;j<NBox;j++){
	  phi[3][i][j]=0.0;
	  phi[4][i][j]=0.0;
	  phi[5][i][j]=1.0;
	}
      }
    }
    */
