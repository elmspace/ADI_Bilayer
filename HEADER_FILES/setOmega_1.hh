/*
In this function, we will initialize the omega fields
*/
void setOmega( ){

  int i, j, chain,ii,jj;
  double epsln=0.1;
  double p_ABC, p_DE, p_F;


  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  Volume=0.0;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      dum_func1[i][j]=1.0;
    }
  }
  Volume=2.0*Pi*integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
  Area=Pi*(R+(drz[0]*NBox/2.0))*(R+(drz[0]*NBox/2.0))-Pi*R*R;
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  

  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  std::ifstream infile;
  if(NBox==32){
    if(Bilayer==1){infile.open("./OMEGA/READ/phi_bilayer_32_32.dat");}
    if(Pore==1){infile.open("./OMEGA/READ/phi_pore_32_32.dat");}
  }else if(NBox==50){
    if(Bilayer==1){infile.open("./OMEGA/READ/omega_bilayer_50_50.dat");}
    if(Pore==1){infile.open("./OMEGA/READ/omega_pore_50_50.dat");}
  }
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      infile >> phi[0][i][j] >> phi[1][i][j] >> phi[2][i][j] >> phi[3][i][j] >> phi[4][i][j] >> phi[5][i][j];

      dum_func1[i][j]=phi[0][i][j]+phi[1][i][j]+phi[2][i][j];
      dum_func2[i][j]=phi[3][i][j]+phi[4][i][j];
      dum_func3[i][j]=phi[5][i][j];
      
    }
  }
  infile.close();
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  p_ABC=integrationTrapezoidal(dum_func1,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
  p_DE=integrationTrapezoidal(dum_func2,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
  p_F=integrationTrapezoidal(dum_func3,0,(NBox-1),0,(NBox-1),drz[0],drz[1],'c');
  p_ABC*=((2.0*Pi)/Volume);
  p_DE*=((2.0*Pi)/Volume);    
  p_F*=((2.0*Pi)/Volume);

  //std::cout<<p_ABC<<" "<<p_DE<<" "<<p_F<<" "<<p_ABC+p_DE+p_F<<std::endl;
  //std::cin>>i;

  phiAve[0]=p_ABC; // ABC Triblock
  phiAve[1]=p_DE; // DE Diblock
  phiAve[2]=p_F; // F Homopolymer
    
  p_ave[0]=phiAve[0]*(double)(Ns[0]/NABC_triblock); // A
  p_ave[1]=phiAve[0]*(double)(Ns[1]/NABC_triblock); // B
  p_ave[2]=phiAve[0]*(double)(Ns[2]/NABC_triblock); // C
  p_ave[3]=phiAve[1]*(double)(Ns[3]/NDE_diblock); // D
  p_ave[4]=phiAve[1]*(double)(Ns[4]/NDE_diblock); // E
  p_ave[5]=phiAve[2]; // F



  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      for(ii=0;ii<ChainType;ii++){
	cal_w[ii][i][j]=0.0;
	for(jj=0;jj<ChainType;jj++){  
	  w[ii][i][j]+=chiMatrix[ii][jj]*phi[jj][i][j];
	}
      }
    }
  }
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  return;

};


















  /*
  if(Bilayer==1){
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[0][i][j]=0.0;
	phi[1][i][j]=0.0;
	phi[2][i][j]=0.0;
	phi[3][i][j]=0.0;
	phi[4][i][j]=0.0;
	phi[5][i][j]=1.0;
      }
    }
    for(i=0;i<NBox;i++){
      for(j=((NBox/2)-3);j<((NBox/2)+3);j++){
	phi[4][i][j]=1.0;
	phi[5][i][j]=0.0;
      }
    }
  }else if(Pore==1){
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[0][i][j]=0.0;
	phi[1][i][j]=0.0;
	phi[2][i][j]=0.0;
	phi[3][i][j]=0.0;
	phi[4][i][j]=0.0;
	phi[5][i][j]=1.0;
      }
    }
    for(i=NBox/2;i<NBox;i++){
      for(j=((NBox/2)-3);j<((NBox/2)+3);j++){
	phi[4][i][j]=1.0;
	phi[5][i][j]=0.0;
      }
    }
  }
  */
