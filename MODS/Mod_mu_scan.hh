/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod_mu_scan( ){
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  mu_d=4.2;
  std::cout<<"+++++"<<std::endl;
  std::cout<<"mu_d"<<" "<<"fE"<<" "<<"fEHom"<<" "<<"Pt"<<" "<<"Pd"<<" "<<"Ph"<<std::endl;
  do{
    calculateFreeEnergy();
    std::cout<<mu_d<<" "<<(totalFreeEnergy/Volume)<<" "<<Homogenous_fE<<" "<<(p_ave[0]+p_ave[1]+p_ave[2])<<" "<<(p_ave[3]+p_ave[4])<<" "<<p_ave[5]<<std::endl;
    mu_d+=0.01;
  }while(mu_d<4.8);
  std::cout<<"+++++"<<std::endl;


  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
