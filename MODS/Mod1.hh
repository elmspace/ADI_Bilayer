/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod1( ){

  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmega();
  allocateMemory(2); // Allocate the q and qdag
  R=2.0;
  std::cout<<"R"<<" "<<"delfE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  do{
    calculateFreeEnergy();
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;
    R+=2.0;
  }while((R+(drz[0]*NBox/2.0))<200.0);
  
  allocateMemory(-1); // Deallocating memory
  
  return;
  
}
