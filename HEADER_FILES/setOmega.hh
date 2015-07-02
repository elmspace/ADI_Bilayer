/*
In this function, we will initialize the omega fields
*/
void setOmega( ){

  int i, j, chain;


  std::ifstream infile;
  if(NBox==32){
    if(Bilayer==1){infile.open("./OMEGA/READ/omega_bilayer_32_32.dat");}
    if(Pore==1){infile.open("./OMEGA/READ/omega_pore_32_32.dat");}
  }else if(NBox==50){
    if(Bilayer==1){infile.open("./OMEGA/READ/omega_bilayer_50_50.dat");}
    if(Pore==1){infile.open("./OMEGA/READ/omega_pore_50_50.dat");}
  }
    
    
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      infile >> w[0][i][j] >> w[1][i][j] >> w[2][i][j] >> w[3][i][j] >> w[4][i][j] >> w[5][i][j];
    }
  }
  infile.close();


  /*
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      w[5][i][j]=-1.0;
    }
  }
  
  for(i=0;i<NBox;i++){
    for(j=((NBox/2)-2);j<((NBox/2)+2);j++){
      w[4][i][j]=-1.0;
      w[3][i][j]=1.0;
      w[5][i][j]=1.0;
    }
  }
  */

    return;

};
