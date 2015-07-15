/*

*/
void setOmegaManual(int phase){

  int i, j, chain,ii,jj;

  // Set to zero --------------------------
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      phi[0][i][j]=0.0;
      phi[1][i][j]=0.0;
      phi[2][i][j]=0.0;
      phi[3][i][j]=0.0;
      phi[4][i][j]=0.0;
      phi[5][i][j]=0.0;
    }
  }
  // --------------------------------------


  if(phase==1){ // Lam Parallel (modulation in z direction)
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[0][i][j]=cos(2.0*Pi*j/NBox)+1.0;
	phi[1][i][j]=-cos(2.0*Pi*j/NBox)+1.0;
	phi[2][i][j]=cos(2.0*Pi*j/NBox)+1.0;
	phi[3][i][j]=cos(2.0*Pi*j/NBox)+1.0;
	phi[4][i][j]=-cos(2.0*Pi*j/NBox)+1.0;
	phi[5][i][j]=0.0;
      }
    }   
  }else if(phase==2){ // Lam Perpendicular (modulation in r direction)
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[0][i][j]=cos(2.0*Pi*i/NBox)+1.0;
	phi[1][i][j]=-cos(2.0*Pi*i/NBox)+1.0;
	phi[2][i][j]=cos(2.0*Pi*i/NBox)+1.0;
	phi[3][i][j]=cos(2.0*Pi*i/NBox)+1.0;
	phi[4][i][j]=-cos(2.0*Pi*i/NBox)+1.0;
	phi[5][i][j]=0.0;
      }
    }
  }else if(phase==3){ // Bilayer

    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[5][i][j]=1.0;
      }
    }
    for(i=(NBox/2);i<NBox;i++){
      for(j=((NBox/2)-3);j<((NBox/2)+3);j++){
	phi[4][i][j]=1.0;
	phi[5][i][j]=0.0;
      }
    }

    
  }


  
  // ( Setting the omega fields ) ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
  
  return;

};


















 
