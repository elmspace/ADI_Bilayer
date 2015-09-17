/*
  In this function, we will initialize the parameters we will be using in the code
*/
void setParameters( ){

  // Hydrophobic/phillic interaction
  double mol_int=0.05;
  
  // Interaction parameters
  double xAB,xAC,xAD,xAE,xAF;
  double xBC,xBD,xBE,xBF;
  double xCD,xCE,xCF;
  double xDE,xDF;
  double xEF;
 

  // Pinning condition
  if(Pore==1 || Disk==1){
    pin_cond = 0.0;
    // Setting the avrerage concentrations______
    phiAve[0]=0.00005; // ABC Triblock
    phiAve[1]=0.15; // DE Diblock
    phiAve[2]=1.0-(phiAve[0]+phiAve[1]); // F Homopolymer
  }else{
    pin_cond = 0.0;
    // Setting the avrerage concentrations______
    phiAve[0]=0.00005; // ABC Triblock
    phiAve[1]=0.1; // DE Diblock
    phiAve[2]=1.0-(phiAve[0]+phiAve[1]); // F Homopolymer
  }
  // Setting the chain lengths________________
  //------------ Diblock
  Ns[3]=50;//ND
  Ns[4]=100-Ns[3];//NE
  //------------ Triblock
  Ns[0]=50;//NA
  Ns[2]=Ns[0];//NC
  Ns[1]=200-(Ns[0]+Ns[2]);//NB
  //------------ Homopolymer
  Ns[5]=Ns[3]+Ns[4];//NF
  //-----------------------------------------
  NABC_triblock=(double)(Ns[0]+Ns[1]+Ns[2]);
  NDE_diblock=(double)(Ns[3]+Ns[4]);
  NF_homopolymer=(double)(Ns[5]);
  f[0]=(double)Ns[0]/NABC_triblock;
  f[1]=(double)Ns[1]/NABC_triblock;
  f[2]=(double)Ns[2]/NABC_triblock;
  f[3]=(double)Ns[3]/NDE_diblock;
  f[4]=(double)Ns[4]/NDE_diblock;
  f[5]=(double)Ns[5]/NF_homopolymer;
  // Chains measured with respect to diblock
  kappa_homopolymer=NF_homopolymer/NDE_diblock;
  kappa_diblock=NDE_diblock/NDE_diblock;
  kappa_triblock=NABC_triblock/NDE_diblock;
  ds=1.0/(NDE_diblock-2);
  // Setting the box dimensions_______________
  R=100.00001;
  LR=4.1;
  LZ=4.1;
  drz[0]=LR/(NBox-1);
  drz[1]=LZ/(NBox-1);
  // Setting individual average concentration_
  p_ave[0]=phiAve[0]*((double)Ns[0]/NABC_triblock); // A
  p_ave[1]=phiAve[0]*((double)Ns[1]/NABC_triblock); // B
  p_ave[2]=phiAve[0]*((double)Ns[2]/NABC_triblock); // C
  p_ave[3]=phiAve[1]*((double)Ns[3]/NDE_diblock); // D
  p_ave[4]=phiAve[1]*((double)Ns[4]/NDE_diblock); // E
  p_ave[5]=phiAve[2]; // F
  // Setting the interactions_________________
  xAB=0.0;//mol_int*NDE_diblock;
  xAC=0.0;
  xAD=0.0;
  xAE=0.0;//mol_int*NDE_diblock;
  xAF=0.0;
  xBC=0.0;//mol_int*NDE_diblock;
  xBD=0.0;//mol_int*NDE_diblock;
  xBE=0.0;
  xBF=0.0;//mol_int*NDE_diblock;
  xCD=0.0;
  xCE=0.0;//mol_int*NDE_diblock;
  xCF=0.0;
  xDE=mol_int*NDE_diblock;
  xDF=0.0;
  xEF=0.0;//mol_int*NDE_diblock;
  // Setting the ChiMatrix ___________________
  chiMatrix[0][0]=0.0;
  chiMatrix[0][1]=xAB;
  chiMatrix[0][2]=xAC;
  chiMatrix[0][3]=xAD;
  chiMatrix[0][4]=xAE;
  chiMatrix[0][5]=xAF;
  //*************
  chiMatrix[1][0]=xAB;
  chiMatrix[1][1]=0.0;
  chiMatrix[1][2]=xBC;
  chiMatrix[1][3]=xBD;
  chiMatrix[1][4]=xBE;
  chiMatrix[1][5]=xBF;
  //*************
  chiMatrix[2][0]=xAC;
  chiMatrix[2][1]=xBC;
  chiMatrix[2][2]=0.0;
  chiMatrix[2][3]=xCD;
  chiMatrix[2][4]=xCE;
  chiMatrix[2][5]=xCF;
  //*************
  chiMatrix[3][0]=xAD;
  chiMatrix[3][1]=xBD;
  chiMatrix[3][2]=xCD;
  chiMatrix[3][3]=0.0;
  chiMatrix[3][4]=xDE;
  chiMatrix[3][5]=xDF;
  //*************
  chiMatrix[4][0]=xAE;
  chiMatrix[4][1]=xBE;
  chiMatrix[4][2]=xCE;
  chiMatrix[4][3]=xDE;
  chiMatrix[4][4]=0.0;
  chiMatrix[4][5]=xEF;
  //*************
  chiMatrix[5][0]=xAF;
  chiMatrix[5][1]=xBF;
  chiMatrix[5][2]=xCF;
  chiMatrix[5][3]=xDF;
  chiMatrix[5][4]=xEF;
  chiMatrix[5][5]=0.0;
  //__________________________________________
  
};
