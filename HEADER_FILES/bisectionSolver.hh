/*
  This function will use the input and calculates the bisection method to find the root
  In this function c is the result
  You do not need to give the function two parameters, it will find the appropiate inputs by itself
*/
double bisectionSolver (double &mu){

  int pass;
  double a,b,c,fa,fb,fc;
  double del_mu=0.1, conv=1.0e-3;

  a=mu;
  calculateFreeEnergy();
  fa=totalFreeEnergy;

  pass=0;
  b=a-0.05;
  do{
    b+=del_mu;
    mu=b;
    calculateFreeEnergy();
    fb=totalFreeEnergy;
    std::cout<<"a= "<<a<<"  fa= "<<fa<<"  b= "<<b<<"  fb= "<<fb<<std::endl;
    if(fa>0.0){
      if(fb>=fa){del_mu*=-1;}
    }else if(fa<0.0){
      if(fb<=fa){del_mu*=-1;}
    }
    if((fa*fb)<0.0){pass=1;}
  }while(pass==0);

  std::cout<<"a= "<<a<<"  fa= "<<fa<<"  b= "<<b<<"  fb= "<<fb<<std::endl;
  std::cout<<"___________"<<std::endl;
  
  pass=0;
  do{
    c=0.5*(a+b);
    mu=c;
    calculateFreeEnergy();
    fc=totalFreeEnergy;
    if(abs(fc)<conv){pass=1;}
    if((fc*fa)>0.0){a=c;}
    if((fc*fb)>0.0){b=c;}
  }while(pass==0);

  std::cout<<"c= "<<c<<"   fc= "<<fc<<std::endl;
  
  return c;
  
};

