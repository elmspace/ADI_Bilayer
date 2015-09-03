/*
  
  Results are saved in /RESULTS/Mod3_Results.dat
*/
void Mod3( ){

 
  std::cout<<"Starting Mod3 function"<<std::endl;
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  double R_Max=30.0;
  double R_Min=0.0;
  
  double mu, mu_Max=5.9;

  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  std::ofstream outputFile1("./RESULTS/Mod3_Results.dat");
  

  if(AB_Hom==1){
    mu_d-=0.1;
  }
  if(ABA_Hom==1){
    mu_t-=0.1;
  }
  do{
    
    R=5.0;
    do{
      calculateFreeEnergy();
      std::cout<<(R+R_tip)<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<" "<<mu_d<<" "<<mu_t<<" "<<mu_h<<std::endl;
      outputFile1<<(R+R_tip)<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<" "<<mu_d<<" "<<mu_t<<" "<<mu_h<<std::endl;
      R+=1.0;
    }while((R+R_tip)<R_Max);
    std::cout<<" "<<std::endl;
    outputFile1<<" "<<std::endl;
    
    if(AB_Hom==1){
      mu_d+=0.025;
      mu=mu_d;
    }
    if(ABA_Hom==1){
      mu_t+=0.025;
      mu=mu_t;
    }
  

  }while(mu<mu_Max);



  outputFile1.close();
  allocateMemory(-1); // Deallocating memory


 
  return;
  
}
