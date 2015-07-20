/*
  This Mod will calculate Free energy as a function of Radius for a range of chemical potentials
  Results are saved in /RESULTS/Mod1_Results.dat
*/
void Mod1( ){

  std::cout<<"Starting Mod1 function"<<std::endl;
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  double mu_Max=4.9;
  double R_Max=30.0;
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  std::ofstream outputFile1("./RESULTS/Mod1_Results.dat");
  outputFile1<<"#"<<"mu"<<" "<<"R+R_tip"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;

  std::cout<<"mu"<<" "<<"R"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  
  do{
    std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    R=0.01;
    do{
      calculateFreeEnergy();
      std::cout<<mu_d<<" "<<(R+R_tip)<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
      outputFile1<<mu_d<<" "<<(R+R_tip)<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
      R+=2.0;
    }while((R+R_tip)<R_Max);

    mu_d+=0.1;
  }while(mu_d<mu_Max);

  outputFile1.close();
  allocateMemory(-1); // Deallocating memory
  
  return;
  
}
