void calculateEta( ){

  int     i,j,chain; 
  double  phiTotal;

  
  phiTotal=0.0;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      phiTotal=0.0;
      del_phi[i][j]=0.0;
      for(chain=0;chain<ChainType;chain++){
	phiTotal+=phi[chain][i][j];
      }
      del_phi[i][j]=1.0-phiTotal;
      eta[i][j]-=del_phi[i][j];
    }
  }
  
  return;
  
};
