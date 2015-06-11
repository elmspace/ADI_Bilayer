void MOD_main_fE_vs_xBI(double ***w, double ***phi, double **psi, double **eta, double **diel_cons, double *Ns, double ds, double **k_vector, double *chi, double *dxy, double **chiMatrix, double ***x_sub, double f){

  // Cleaning the .dat file
  std::ofstream outputFile37("./RESULTS/MOD_main_fE_vs_xBI.dat");
  outputFile37 << std::endl;
  outputFile37.close();
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  double fE_Phase;
  
  int i, j;
  double delxBI, MaxxBI;
  

  MaxxBI = 200.0;
  delxBI = 10.0;

  parametersAB(chi,f,ds,Ns,dxy,chiMatrix,x_sub);

  // Charge percentage 1e-10 is 0
  PA=0.001;
  pIave=PA*pAave;
  
  // Overwriting the chosen parameters:
  // Potential difference *************************
  psi_bc_1=5.0;
  psi_bc_2=0.0; // Will be kept at zero all the time
  //+++++++++++++++++++++++++++++++++++

   // Interaction parameters ++++++++++++++++++++++++++++++++++++
  chi[0]=20.0;  //xAB
  chi[1]=0.0;  //xAI
  chi[2]=0.0;  //xBI
  // Setting up the interaction matrix
  chiMatrix[0][0]=0.0;     // xAA
  chiMatrix[0][1]=chi[0];  // xAB
  chiMatrix[0][2]=chi[1];  // xAI
  chiMatrix[1][0]=chi[0];  // xAB
  chiMatrix[1][1]=0.0;     // xBB
  chiMatrix[1][2]=chi[2];  // xBI
  chiMatrix[2][0]=chi[1];  // xAI
  chiMatrix[2][1]=chi[2];  // xBI
  chiMatrix[2][2]=0.0;  // xII
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  PER=0;             // perpendicular
  PAR_AS=1;          // parallel A by substrate
  PAR_BS=0;          // parallel B by substrate
  MIX=0;             // mixed

  omega(w);
  
  do{
     
    fE_Phase=FreeEnergy(w,phi,psi,eta,diel_cons,Ns,ds,k_vector,chi,dxy,chiMatrix,x_sub);
     
    
    std::cout<<"xBI="<<chi[2]<<" "<<"  PA="<<PA<<" "<<"  fE_Phase="<<fE_Phase<<" "<<"  tau="<<tau<<std::endl;
    
    std::ofstream outputFile37("./RESULTS/MOD_main_fE_vs_xBI.dat" , ios::app);
    outputFile37 <<chi[2]<<" "<<PA<<" "<<fE_Phase<<std::endl;
    outputFile37.close(); 
    
    // Interaction parameters ++++++++++++++++++++++++++++++++++++
    chi[0]=20.0;  //xAB
    chi[1]=0.0;  //xAI
    chi[2]+=delxBI;  //xBI
    // Setting up the interaction matrix
    chiMatrix[0][0]=0.0;     // xAA
    chiMatrix[0][1]=chi[0];  // xAB
    chiMatrix[0][2]=chi[1];  // xAI
    chiMatrix[1][0]=chi[0];  // xAB
    chiMatrix[1][1]=0.0;     // xBB
    chiMatrix[1][2]=chi[2];  // xBI
    chiMatrix[2][0]=chi[1];  // xAI
    chiMatrix[2][1]=chi[2];  // xBI
    chiMatrix[2][2]=0.0;  // xII
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    
  }while(chi[2]<MaxxBI);
  
  
  Save_Stuff(w,phi,psi,diel_cons);
  
};
