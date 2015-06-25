double calculatedHomogenousEnergy( ){

  int     i,j;
  double  fE_homo;

  fE_homo=0.0;
  for(i=0;i<ChainType;i++){
    for(j=0;j<ChainType;j++){
      fE_homo+=p_ave[i]*p_ave[j]*chiMatrix[i][j];
    }
  }
  fE_homo/=2.0;

  fE_homo*=Pi*(drz[1]*(NBox))*(((R+(drz[0]*(NBox+1)))*(R+(drz[0]*(NBox+1))))-(R*R));
  fE_homo/=Volume;
  
  return fE_homo;

};
