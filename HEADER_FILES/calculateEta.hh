void calculateEta( ){

  int     i,j,chain; 
  double  phiTotal;
  double pin_delphi;

  
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

  pin_delphi=(phi[0][NBox/2][NBox/2]+phi[2][NBox/2][NBox/2]+phi[3][NBox/2][NBox/2]+phi[5][NBox/2][NBox/2])   -   (phi[1][NBox/2][NBox/2]+phi[4][NBox/2][NBox/2]);
  pin[NBox/2][NBox/2]-=pin_cond*pin_delphi;
  
  return;
  
};
