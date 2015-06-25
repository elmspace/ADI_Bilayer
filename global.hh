#include <stdio.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <stdlib.h> 
#include <math.h>      
#include "./INCLUDE/smemory.hh"
using namespace std;

#define Pi 3.14159

#define NBox 32
#define ChainType 6
#define deltaBox 0.1/NBox

// Relative chain lengths
double kappa_homopolymer;
double kappa_diblock;
double kappa_triblock;

// Single chain partition functions
double Q_ABC, Q_DE, Q_F;

// Component of free energy
double totalFreeEnergy, Interaction_fE, Omega_fE, Entropy_fE, Homogenous_fE;

// Distance from center of cylinder
double R;

// Volume of the system
double Volume;

// Simple mixing parameters 
double epsilon_w=0.1;
double epsilon_phi=0.1;

// Control parameters
double delta_W, delta_Phi;
double precision=1.0e-3;

double LR, LZ;
double ***w, ***phi, *phiAve, *p_ave;
double  ***cal_w, ***del_w, **del_phi;
double **eta, **chiMatrix;
double ds, *drz;
int *Ns;


// Propagators
double ***q0, ***q0dag;
double ***q1, ***q1dag;
double ***q2, ***q2dag;
double ***q3, ***q3dag;
double ***q4, ***q4dag;
double ***q5, ***q5dag;
double **qini, **qmid;

// ADI Parameters
double *Mu, *Mm, *Ml;
double *Rvector; 

// dummy functions
double **dum_func1,**dum_func2,**dum_func3;



