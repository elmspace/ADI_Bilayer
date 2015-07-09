/*
  This Mod will calculate Free energy as a function of Radius
*/
void Mod_basic( ){

  int i, fE_p, fE_b;

  allocateMemory(1); // Allocate the first set
  setParameters();
  allocateMemory(2); // Allocate the q and qdag
  R=1.0;
  do{

    for(i=0;i<2;i++){
      if(i==0){
	Bilayer = 1;
	Pore = 0;
	setOmega();
	calculateFreeEnergy();
	fE_b=(totalFreeEnergy*Volume);
      }else{
	Bilayer = 0;
	Pore = 1;
	setOmega();
	calculateFreeEnergy();
	fE_p=(totalFreeEnergy*Volume);
      }
    }
    std::cout<<(R+(drz[0]*NBox/2.0))<<" "<<fE_p<<" "<<fE_b<<" "<<Volume<<" "<<Area<<std::endl;
	
    R+=5.0;
    
  }while(R<50.0);

  allocateMemory(-1); // Deallocating memory
    
  return;
  
}
