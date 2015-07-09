/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod1( ){

  Bilayer = 1;
  Pore = 0;
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmega();
  allocateMemory(2); // Allocate the q and qdag
  
  mu_d=bisectionSolver(mu_d);
  Bilayer = 0;
  Pore = 1;
  pin_cond = 1.0;
  setOmega();

  std::cout<<"R"<<" "<<"delfE"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  do{
    calculateFreeEnergy();
    
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<totalFreeEnergy<<" "<<Volume<<" "<<Area<<std::endl;
    
    R-=1.0;
  }while((R+(drz[0]*NBox/2.0))>2.0);
  
  allocateMemory(-1); // Deallocating memory
  
  return;
  
}
