/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod1( ){

  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual(5);
  allocateMemory(2); // Allocate the q and qdag
  
  std::cout<<"R"<<" "<<"delfE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  std::ofstream outputFile1("./RESULTS/fE_vs_R.dat");
  outputFile1<<"#"<<" "<<"R"<<" "<<"R+Rpin"<<" "<<"delfE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;

  
  R=0.5;
  do{
    calculateFreeEnergy();
    std::cout<<R<<" "<<(R+(drz[0]*NBox/2.0))<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
    outputFile1<<R<<" "<<(R+(drz[0]*NBox/2.0))<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
    R+=0.5;
  }while((R+(drz[0]*NBox/2.0))<30.0);

  
  outputFile1.close();
  allocateMemory(-1); // Deallocating memory
  
  return;
  
}
