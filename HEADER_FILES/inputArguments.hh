void inputArguments(int numb_of_args, char* arg_input[]){

  double chem_readin;

  if(strcmp( arg_input[1], "B") == 0){
    Bilayer=1;
  }else if(strcmp( arg_input[1], "P") == 0){
    Pore=1;
  }else if(strcmp( arg_input[1], "D") == 0){
    Disk=1;
  }else{
    std::cout<<"The phase you have chosen does not exists!"<<std::endl;
    exit(1);
  }
 

  chem_readin=atof(arg_input[3]);
  if(!(chem_readin==0.0)){
    if(AB_Hom==1){
      mu_t=-200.0;
      mu_h=0.0;
      mu_d=chem_readin;
      mu_ref=mu_h;
    }else if(ABA_Hom==1){
      mu_t=chem_readin;
      mu_h=0.0;
      mu_d=-200.0;
      mu_ref=mu_h;
    }else if(AB_ABA_Hom==1){
      mu_t=chem_readin;
      mu_h=0.0;
      mu_d=chem_readin;
      mu_ref=mu_h;
    }else{
      std::cout<<"Something is wrong in the inputArguments.hh"<<std::endl;
      exit(1);
    }
  }else{
    std::cout<<"The chemical potential input is not correct. Something is wrong in the inputArguments.hh"<<std::endl;
    exit(1);
  }

};
