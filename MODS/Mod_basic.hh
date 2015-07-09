/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod_basic( ){

  allocateMemory(1); // Allocate the first set
  setParameters();
  allocateMemory(2); // Allocate the q and qdag
  R=1.0;
  do{
    
    setOmega();
    calculateFreeEnergy();
    
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;
    
    R+=2.0;
    
  }while(R<50.0);
  
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
