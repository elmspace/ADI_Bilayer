/*
This program uses the ADI method for solving the diffusion equation
Written By:   Ashkan Dehghan [McMaster University]
*/
#include "./global.hh"
#include "./HEADER_FILES/allocateMemory.hh"
#include "./HEADER_FILES/integrationTrapezoidal.hh"
#include "./HEADER_FILES/setParameters.hh"
#include "./HEADER_FILES/setOmega.hh"
#include "./HEADER_FILES/TDI.hh"
#include "./HEADER_FILES/ADI.hh"
#include "./HEADER_FILES/solveDiffusionEquation.hh"
#include "./HEADER_FILES/calculatePhi.hh"
#include "./HEADER_FILES/calculateEta.hh"
#include "./HEADER_FILES/calculateOmega.hh"
#include "./HEADER_FILES/saveData.hh"
#include "./HEADER_FILES/calculateHomogenousEnergy.hh"
#include "./HEADER_FILES/calculateFreeEnergy.hh"
#include "./HEADER_FILES/boxMinimize.hh"

using namespace std;

int main(){

  allocateMemory(1); // Allocate the first set
  setOmega();
  setParameters();
  allocateMemory(2); // Allocate the q and qdag

  //boxMinimize();

  calculateFreeEnergy();

  allocateMemory(-1); // Deallocating memory
  
  return 0;
}

