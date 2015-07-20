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
#include "./MODS/Mod1.hh"
#include "./MODS/Mod_basic.hh"
#include "./MODS/Mod_Test_1.hh"
#include "./MODS/Mod_mu_scan.hh"

using namespace std;

int main(int argc, char* argv[]){

  // The arguments read in are in order:
  // 1-> B=Bilayer P=Pore D=Disk
  // 2-> 
  // 3-> 
  // 4-> 

  inputArguments(argc,argv);
  
  //Mod_mu_scan();
  //Mod_basic();
  //Mod_Test_1();
  Mod1();
  
  return 0;
}

