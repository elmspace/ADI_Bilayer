void saveData( ){

  int i, j ,k;
  int J, I;
  
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile1("./PHI/phi_r.dat");
  J=NBox/2;
  for(i=0;i<NBox;i++){
    outputFile1 <<i*drz[0]<<" "<<phi[0][i][J]<<" "<<phi[1][i][J]<<" "<<phi[2][i][J]<<" "<<phi[3][i][J]<<" "<<phi[4][i][J]<<" "<<phi[5][i][J]<<std::endl;
  }
  outputFile1.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile2("./PHI/phi_z.dat");
  if(Pore==1){
    I=NBox-1;
  }else if(Disk==1){
    I=0;
  }else  if(Bilayer==1){
    I=NBox/2;
  }else{
    I=NBox/2;
  }
  for(j=0;j<NBox;j++){
    outputFile2 <<j*drz[1]<<" "<<phi[0][I][j]<<" "<<phi[1][I][j]<<" "<<phi[2][I][j]<<" "<<phi[3][I][j]<<" "<<phi[4][I][j]<<" "<<phi[5][I][j]<<std::endl;
  }
  outputFile2.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile3("./PHI/phi2D.dat");
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      outputFile3 <<i*drz[0]<<" "<<j*drz[1]<<" "<<phi[0][i][j]<<" "<<phi[1][i][j]<<" "<<phi[2][i][j]<<" "<<phi[3][i][j]<<" "<<phi[4][i][j]<<" "<<phi[5][i][j]<<std::endl;
    }
  }
  outputFile3.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile4("./OMEGA/omega.dat");
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      outputFile4 <<w[0][i][j]<<" "<<w[1][i][j]<<" "<<w[2][i][j]<<" "<<w[3][i][j]<<" "<<w[4][i][j]<<" "<<w[5][i][j]<<std::endl;
    }
  }
  outputFile4.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile5("./OMEGA/phi.dat");
  for(i=0;i<NBox;i++){
    for(j=0;j<NBox;j++){
      outputFile5 <<phi[0][i][j]<<" "<<phi[1][i][j]<<" "<<phi[2][i][j]<<" "<<phi[3][i][j]<<" "<<phi[4][i][j]<<" "<<phi[5][i][j]<<std::endl;
    }
  }
  outputFile5.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 
};



