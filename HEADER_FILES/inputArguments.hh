void inputArguments(int numb_of_args, char* arg_input[]){

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
  mu_d=atof(arg_input[2]);

};
