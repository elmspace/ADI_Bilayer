void calculateEta( ){

  int     i,j,chain;
  int     dum1,dum2;
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
  
  if(Pore==1 || Disk==1){
    j=NBox/2;
    i=0;
    dum1=(phi[0][i][j]+phi[2][i][j]+phi[3][i][j]+phi[5][i][j]-phi[1][i][j]-phi[4][i][j]);
    if(dum1<0){dum2=-1;}
    if(dum1>0){dum2=1;}
    for(i=0;i<NBox;i++){
      dum1=(phi[0][i][j]+phi[2][i][j]+phi[3][i][j]+phi[5][i][j]-phi[1][i][j]-phi[4][i][j]);
      if(double(dum1*dum2)<0.0){
	R_tip=drz[0]*double(i);
	break;
      }
    }
  }
    
  pin_delphi=(phi[0][NBox/2][NBox/2]+phi[2][NBox/2][NBox/2]+phi[3][NBox/2][NBox/2]+phi[5][NBox/2][NBox/2])   -   (phi[1][NBox/2][NBox/2]+phi[4][NBox/2][NBox/2]);
  pin[NBox/2][NBox/2]-=pin_cond*pin_delphi;
  
  return;
  
};
