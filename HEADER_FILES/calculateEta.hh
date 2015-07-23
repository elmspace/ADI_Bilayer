void calculateEta( ){

  int     i,j,chain;
  double     dum1,dum2;
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
    if(dum1<0.0){dum2=-1.0;}
    if(dum1>0.0){dum2=1.0;}
    for(i=0;i<NBox;i++){
      dum1=(phi[0][i][j]+phi[2][i][j]+phi[3][i][j]+phi[5][i][j]-phi[1][i][j]-phi[4][i][j]);
      if(double(dum1*dum2)<0.0){
	R_tip=drz[0]*double(i);
	break;
      }
    }


    if(iter_global==50){
      I_pin=i;
      J_pin=j;
      pin_cond=1.0;
    }
  }

  
  pin_delphi=(phi[0][I_pin][J_pin]+phi[2][I_pin][J_pin]+phi[3][I_pin][J_pin]+phi[5][I_pin][J_pin]-phi[1][I_pin][J_pin]-phi[4][I_pin][J_pin]);
  pin[I_pin][J_pin]-=pin_cond*pin_delphi;
  
  return;
  
};
