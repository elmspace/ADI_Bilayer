/*
  This Mod will calculate Free energy as a function of Radius
  Results are saved in /RESULTS/Mod1_Results.dat
*/
void Mod3( ){

  double F1, F2;
  double R1, R2;
  double slope, y_intercept;
  int i;
  
 
  N_global=30;
  do{
    
    allocateMemory(1); // Allocate the first set
    setParameters();
    setOmegaManual();
    allocateMemory(2); // Allocate the q and qdag
  
    for(i=0;i<2;i++){
      if(i==0){R=0.01;}
      if(i==1){R=10.0;}   
      calculateFreeEnergy();
      //std::cout<<R<<" "<<R_tip<<" "<<((totalFreeEnergy-Homogenous_fE)/Volume)*Area/(R+R_tip)<<std::endl;
      if(i==0){
	F1=((totalFreeEnergy-Homogenous_fE)/Volume)*Area/(R+R_tip);
	R1=(R+R_tip);
      }
      if(i==1){
	F2=((totalFreeEnergy-Homogenous_fE)/Volume)*Area/(R+R_tip);
	R2=(R+R_tip);
      }
    }

    slope=(F2-F1)/(R2-R1);
    y_intercept=F2-slope*R2;

    std::cout<<f[3]<<" "<<slope<<" "<<y_intercept<<std::endl;

    pin_cond=0.0;
    N_global+=2;

    allocateMemory(-1); // Deallocating memory
  
  }while(N_global<72);
  
  return;
  
}
