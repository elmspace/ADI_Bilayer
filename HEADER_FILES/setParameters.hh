/*
  In this function, we will initialize the parameters we will be using in the code
*/
void setParameters( ){

  // Hydrophobic/phillic interaction
  double mol_int=0.02;
  
  // Interaction parameters
  double xAB,xAC,xAD,xAE,xAF;
  double xBC,xBD,xBE,xBF;
  double xCD,xCE,xCF;
  double xDE,xDF;
  double xEF;
  // Chain polymerization
  double NABC_triblock, NDE_diblock, NF_homopolymer; 
  

  // Setting the avrerage concentrations______
  phiAve[0]=0.00005; // ABC Triblock
  phiAve[1]=0.9999; // DE Diblock
  phiAve[2]=1.0-(phiAve[0]+phiAve[1]); // F Homopolymer
  // Setting the chain lengths________________
  Ns[0]=2;//NA
  Ns[1]=2;//NB
  Ns[2]=2;//NC
  Ns[3]=50;//ND
  Ns[4]=50;//NE
  Ns[5]=2;//NF
  NABC_triblock=Ns[0]+Ns[1]+Ns[2];
  NDE_diblock=Ns[3]+Ns[4];
  NF_homopolymer=Ns[5];
  // Chains measured with respect to diblock
  kappa_homopolymer=NF_homopolymer/NDE_diblock;
  kappa_diblock=NDE_diblock/NDE_diblock;
  kappa_triblock=NABC_triblock/NDE_diblock;
  ds=1.0/NDE_diblock;
  // Setting the box dimensions_______________
  R=600.0;
  LR=4.0;
  LZ=4.0;
  drz[0]=LR/NBox;
  drz[1]=LZ/NBox;
  // Setting individual average concentration_
  p_ave[0]=phiAve[0]*(double)(Ns[0]/NABC_triblock); // A
  p_ave[1]=phiAve[0]*(double)(Ns[1]/NABC_triblock); // B
  p_ave[2]=phiAve[0]*(double)(Ns[2]/NABC_triblock); // C
  p_ave[3]=phiAve[1]*(double)(Ns[3]/NDE_diblock); // D
  p_ave[4]=phiAve[1]*(double)(Ns[4]/NDE_diblock); // E
  p_ave[5]=phiAve[2]; // F
  // Setting the interactions_________________

  xAB=mol_int*NDE_diblock;
  xAC=0.0;
  xAD=0.0;
  xAE=mol_int*NDE_diblock;
  xAF=0.0;
  xBC=mol_int*NDE_diblock;
  xBD=mol_int*NDE_diblock;
  xBE=0.0;
  xBF=mol_int*NDE_diblock;
  xCD=0.0;
  xCE=mol_int*NDE_diblock;
  xCF=0.0;
  xDE=mol_int*NDE_diblock;
  xDF=0.0;
  xEF=mol_int*NDE_diblock;
  
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
