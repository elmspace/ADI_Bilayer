void calculateOmega( ){

  int i, j;
  int ii, jj;

  delta_W=0.0;
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      
      for(ii=0;ii<ChainType;ii++){
	cal_w[ii][i][j]=0.0;
	for(jj=0;jj<ChainType;jj++){  
	  cal_w[ii][i][j]+=chiMatrix[ii][jj]*(phi[jj][i][j]-p_ave[jj]);
	}
	cal_w[ii][i][j]+=eta[i][j];
	del_w[ii][i][j]=cal_w[ii][i][j]-w[ii][i][j];
	delta_W+=abs(del_w[ii][i][j]);
	// Updating omega fileds
	w[ii][i][j]+=epsilon_w*del_w[ii][i][j]-epsilon_phi*del_phi[i][j];
      }
    }
  }
  delta_W/=(NBox*NBox);
  return;
 
};

