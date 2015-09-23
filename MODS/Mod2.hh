/*
  This Mod will calculate Free energy as a function of chemical potential
*/
void Mod2( ){

  std::cout<<"Starting Mod2 function"<<std::endl;
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  double mu, mu_Lim=5.9;
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  std::ofstream outputFile1("./RESULTS/Mod2_Results.dat");
  outputFile1<<"#"<<"mu_d"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  std::cout<<"mu_d"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
 
  do{
    calculateFreeEnergy();
 
    std::cout<<mu_d<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
    outputFile1<<mu_d<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
    mu_d+=0.05;
    mu=mu_d;
  
  }while(mu<mu_Lim);
  std::cout<<"+++++++++++++++++++++++++++"<<std::endl;

  outputFile1.close();
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
