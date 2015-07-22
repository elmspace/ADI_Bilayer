#include <stdio.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <stdlib.h> 
#include <math.h>      
#include "./include/smemory.hh"
using namespace std;

#define Pi 3.14159

#define NBox 64
#define ChainType 6
#define deltaBox 0.1/NBox

// Choosing the type of ensemble
int Canonical = 0;
int GrandCanonical = 1;

int Bilayer = 0;
int Pore = 0;
int Disk = 0;

int print_fE = 0;

double pin_cond;
int iter_global, I_pin, J_pin;
  
// Simple mixing parameters 
double epsilon_w=0.05;
double epsilon_phi=0.05;

// Relative chain lengths
double kappa_homopolymer;
double kappa_diblock;
double kappa_triblock;

// Single chain partition functions
double Q_ABC, Q_DE, Q_F;

// Component of free energy
double totalFreeEnergy, Interaction_fE, Omega_fE, Entropy_fE, Homogenous_fE;

// Chemical potential
double mu_t, mu_d, mu_h;
double act_h, act_t, act_d, mu_ref;

// Chain polymerization
double NABC_triblock, NDE_diblock, NF_homopolymer;

// Distance from center of cylinder
double R, R_tip=0.0;

// Volume of the system
double Volume, Area;

// Control parameters
double delta_W, delta_Phi;
double precision=1.0e-3;

double LR, LZ;
double ***w, ***phi, *phiAve, *p_ave, *w_ave;
double  ***cal_w, ***del_w, **del_phi, *del_w_ave;
double **eta, **pin, **chiMatrix;
double ds, *drz;
double *f;
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



