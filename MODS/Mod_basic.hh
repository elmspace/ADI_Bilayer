/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod_basic( ){
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag
  //mu_d=bisectionSolver(mu_d);
  calculateFreeEnergy();
  
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
