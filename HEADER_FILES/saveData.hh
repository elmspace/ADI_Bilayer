void saveData( ){

  int i, j ,k;

  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile1("./PHI/phi_r.dat");
  for(i=0;i<NBox;i++){
    outputFile1 <<i*drz[0]<<" "<<phi[0][i][NBox/2]<<" "<<phi[1][i][NBox/2]<<" "<<phi[2][i][NBox/2]<<" "<<phi[3][i][NBox/2]<<" "<<phi[4][i][NBox/2]<<" "<<phi[5][i][NBox/2]<<std::endl;
  }
  outputFile1.close();
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // Writting to data files
  std::ofstream outputFile2("./PHI/phi_z.dat");
  for(i=0;i<NBox;i++){
    outputFile2 <<i*drz[1]<<" "<<phi[0][NBox/2][i]<<" "<<phi[1][NBox/2][i]<<" "<<phi[2][NBox/2][i]<<" "<<phi[3][NBox/2][i]<<" "<<phi[4][NBox/2][i]<<" "<<phi[5][NBox/2][i]<<std::endl;
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
 
};



