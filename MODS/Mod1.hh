/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod1( ){

  R=1.0;
  Bilayer = 1;
  Pore = 0;
  pin_cond = 0.0;
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
    
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<(totalFreeEnergy*Volume)<<" "<<Homogenous_fE*Volume<<" "<<Volume<<" "<<Area<<std::endl;

    R+=2.5;
  }while((R+(drz[0]*NBox/2.0))<200.0);
  
  allocateMemory(-1); // Deallocating memory
  
  return;
  
}
