/*
  This Mod will calculate Free energy
*/
void Mod0( ){

  print_fE=1;
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag
  calculateFreeEnergy();
  std::cout<<"NBox"<<" "<<"fE/Vol"<<std::endl;
  std::cout<<NBox<<" "<<(totalFreeEnergy-Homogenous_fE)/Volume<<std::endl;
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
