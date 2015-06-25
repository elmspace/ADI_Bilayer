/*
  This function will calculate all the phi values using a Trapozoildal integration
*/
void calculatePhi(){

  int i, j, chain, s;
  
  for(chain=0;chain<ChainType;chain++){
    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	phi[chain][i][j]=0.0;
	for(s=0;s<Ns[chain];s++){
	  
	  if((s==0) || (s==(Ns[chain]-1))){
	    if(chain==0){phi[chain][i][j]+=0.5*q0[i][j][s]*q0dag[i][j][(Ns[chain]-1)-s]*ds;}	    
	    if(chain==1){phi[chain][i][j]+=0.5*q1[i][j][s]*q1dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==2){phi[chain][i][j]+=0.5*q2[i][j][s]*q2dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==3){phi[chain][i][j]+=0.5*q3[i][j][s]*q3dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==4){phi[chain][i][j]+=0.5*q4[i][j][s]*q4dag[i][j][(Ns[chain]-1)-s]*ds;}
	    if(chain==5){phi[chain][i][j]+=0.5*q5[i][j][s]*q5dag[i][j][(Ns[chain]-1)-s]*ds;}
	  }else{
	    if(chain==0){phi[chain][i][j]+=q0[i][j][s]*q0dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==1){phi[chain][i][j]+=q1[i][j][s]*q1dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==2){phi[chain][i][j]+=q2[i][j][s]*q2dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==3){phi[chain][i][j]+=q3[i][j][s]*q3dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==4){phi[chain][i][j]+=q4[i][j][s]*q4dag[i][j][Ns[chain]-s]*ds;}
	    if(chain==5){phi[chain][i][j]+=q5[i][j][s]*q5dag[i][j][Ns[chain]-s]*ds;}
	  }
	}
	if(chain==0){phi[chain][i][j]*=phiAve[0]/(kappa_triblock*Q_ABC);}
	if(chain==1){phi[chain][i][j]*=phiAve[0]/(kappa_triblock*Q_ABC);}
	if(chain==2){phi[chain][i][j]*=phiAve[0]/(kappa_triblock*Q_ABC);}
	if(chain==3){phi[chain][i][j]*=phiAve[1]/(kappa_diblock*Q_DE);}
	if(chain==4){phi[chain][i][j]*=phiAve[1]/(kappa_diblock*Q_DE);}
	if(chain==5){phi[chain][i][j]*=phiAve[2]/(kappa_homopolymer*Q_F);}
      }
    }
  }

  return;
  
};
