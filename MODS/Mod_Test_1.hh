void Mod_Test_1( ){


  // For Perpendicular Now **************************************************************************************************************


  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual(2);
  // Setting the chemical potentials
  mu_t=-50.0;
  mu_h=-50.0;
  mu_d=0.0;
  mu_ref=mu_d;
  allocateMemory(2); // Allocate the q and qdag
  R=5.0;
  std::ofstream outputFile2("./RESULTS/fE_vs_R_Per.dat");
  do{
    calculateFreeEnergy();
    outputFile2<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;
    R+=5.0;
  }while(R<100.0);
  outputFile2.close();
  allocateMemory(-1); // Deallocating memory

  
  int i;
  std::cin>>i;
  
  
 // For Parallel Now **************************************************************************************************************
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual(1);
  // Setting the chemical potentials
  mu_t=-50.0;
  mu_h=-50.0;
  mu_d=0.0;
  mu_ref=mu_d;
  allocateMemory(2); // Allocate the q and qdag
  R=5.0;
  std::ofstream outputFile1("./RESULTS/fE_vs_R_Par.dat");
  do{
    calculateFreeEnergy();
    outputFile1<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;
    R+=5.0;
  }while(R<100.0);
  outputFile1.close();
  allocateMemory(-1); // Deallocating memory

  return;
  
}


