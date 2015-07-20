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
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
