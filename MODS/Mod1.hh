/*
  In Mod1, we calculate the Free energy as a function of radius.
  The result is saved in RESULTS/Mod1_Results.dat
  You can plot the results by running the Mod1_Result.p script in Gnuplot platform
*/
void Mod1( ){

  std::cout<<"Starting Mod1 function"<<std::endl;
  std::cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
  
  double R_Max=100.0;
  double R_Min=0.0;

  allocateMemory(1); // Allocate the first set
  setParameters();
  setOmegaManual();
  allocateMemory(2); // Allocate the q and qdag

  std::ofstream outputFile1("./RESULTS/Mod1_Results.dat");
  outputFile1<<"#"<<" "<<"R+R_tip"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<" "<<"mu_d"<<" "<<"mu_t"<<" "<<"mu_h"<<std::endl;

  std::cout<<"R+R_tip"<<" "<<"fE"<<" "<<"fE_homo"<<" "<<"Volume"<<" "<<"Area"<<" "<<"mu_d"<<" "<<"mu_t"<<" "<<"mu_h"<<std::endl;
 
  R=1.0;
  do{
    calculateFreeEnergy();
    std::cout<<(R+R_tip)<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<" "<<mu_d<<" "<<mu_t<<" "<<mu_h<<std::endl;
    outputFile1<<(R+R_tip)<<" "<<totalFreeEnergy<<" "<<Homogenous_fE<<" "<<Volume<<" "<<Area<<" "<<mu_d<<" "<<mu_t<<" "<<mu_h<<std::endl;
    R+=3.0;
  }while((R+R_tip)<R_Max);
  
  outputFile1.close();
  allocateMemory(-1); // Deallocating memory
  
  return;
  
}
