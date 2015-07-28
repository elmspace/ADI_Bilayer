/*
This program uses the ADI method for solving the diffusion equation
Written By:   Ashkan Dehghan [McMaster University]
*/
#include "./global.hh"
#include "./HEADER_FILES/inputArguments.hh"
#include "./HEADER_FILES/allocateMemory.hh"
#include "./HEADER_FILES/integrationTrapezoidal.hh"
#include "./HEADER_FILES/setParameters.hh"
#include "./HEADER_FILES/setOmega.hh"
#include "./HEADER_FILES/setOmegaManual.hh"
#include "./HEADER_FILES/TDI.hh"
#include "./HEADER_FILES/ADI.hh"
#include "./HEADER_FILES/solveDiffusionEquation.hh"
#include "./HEADER_FILES/calculatePhi.hh"
#include "./HEADER_FILES/calculateEta.hh"
#include "./HEADER_FILES/calculateOmega.hh"
#include "./HEADER_FILES/saveData.hh"
#include "./HEADER_FILES/calculateHomogenousEnergy.hh"
#include "./HEADER_FILES/calculateFreeEnergy.hh"
#include "./HEADER_FILES/bisectionSolver.hh"
#include "./HEADER_FILES/boxMinimize.hh"
#include "./MODS/Mod0.hh"
#include "./MODS/Mod1.hh"
#include "./MODS/Mod2.hh"
#include "./MODS/Mod3.hh"

using namespace std;

int main(int argc, char* argv[]){

  // The arguments read in are in order:
  // 1-> B=Bilayer P=Pore D=Disk
  // Mod number

  inputArguments(argc,argv);

  Mod_global=atoi(argv[2]);
  
  if(atoi(argv[2])==0){Mod0();}
  else if(atoi(argv[2])==1){Mod1();}
  else if(atoi(argv[2])==2){Mod2();}
  else if(atoi(argv[2])==3){Mod3();}
  else{
    std::cout<<"The Mod you have chosen does not exists, please look at main.cpp"<<std::endl;
    exit(1);
  }
  
  return 0;
}

/* Mod descriptions

   Mod0 -> In Mod0, we calculate the free energy for a give set of parameters. Results are printed and not saved, this mode is mainly for testing. 

   Mod1 -> In Mod1, we calculate the Free energy as a function of radius. The result is saved in RESULTS/Mod1_Results.dat

   Mod2 -> In Mod2, we calculate the Free energy as a function of chemical potential. The result is saved in RESULTS/Mod2_Results.dat

*/

