/*
  This Mod will calculate Free energy as a function of chemical potential
*/
void Mod2( ){

  std::cout<<"Starting Mod2 function"<<std::endl;
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  double mu, mu_Max=5.9;
  
  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  std::ofstream outputFile1("./RESULTS/Mod2_Results.dat");
  if(AB_Hom==1){
    outputFile1<<"#"<<"mu_d"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
    std::cout<<"mu_d"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  }else if(ABA_Hom==1){
    outputFile1<<"#"<<"mu_t"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
    std::cout<<"mu_t"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<std::endl;
  }else{
    std::cout<<"The blend you have chosen does not fit this function!"<<std::endl;
    exit(1);
  }

  do{
    calculateFreeEnergy();
    if(AB_Hom==1){
      std::cout<<mu_d<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
      outputFile1<<mu_d<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
      mu_d+=0.05;
      mu=mu_d;
    }else if(ABA_Hom==1){
      std::cout<<mu_t<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
      outputFile1<<mu_t<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<std::endl;
      mu_t+=0.05;
      mu=mu_t;
    }else{
      std::cout<<"The blend you have chosen does not fit this function!"<<std::endl;
      exit(1);
    }  
  }while(mu<mu_Max);
  std::cout<<"+++++++++++++++++++++++++++"<<std::endl;

  outputFile1.close();
  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
