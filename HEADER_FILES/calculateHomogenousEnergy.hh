double calculatedHomogenousEnergy( ){

  int    i, j, ii, jj, chain, iter;
  double eta_ave;
  double dp, dw;
  double Qt_ave, Qd_ave, Qh_ave; 
  double fE_homo;


  if(Canonical==1){ //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
    fE_homo=0.0;
    for(i=0;i<ChainType;i++){
      for(j=0;j<ChainType;j++){
	fE_homo+=p_ave[i]*p_ave[j]*chiMatrix[i][j];
      }
    }
    fE_homo/=2.0;

  }else if(GrandCanonical==1){ //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    p_ave[0]=0.002;
    p_ave[1]=0.002;
    p_ave[2]=0.002;
    p_ave[3]=0.002;
    p_ave[4]=0.002;
    p_ave[5]=1.0-(p_ave[0]+p_ave[1]+p_ave[2]+p_ave[3]+p_ave[4]);
    for(chain=0;chain<ChainType;chain++){
      del_w_ave[chain]=0.0;
    }
    eta_ave=0.0;
    
    for(ii=0;ii<ChainType;ii++){
      w_ave[ii]=0.0;
      for(jj=0;jj<ChainType;jj++){  
	w_ave[ii]+=chiMatrix[ii][jj]*p_ave[jj];
      }
      w_ave[ii]+=eta_ave;
    }
    
    iter=0;
    do{
      
      eta_ave=eta_ave-0.05*(1.0-(p_ave[0]+p_ave[1]+p_ave[2]+p_ave[3]+p_ave[4]+p_ave[5]));

      Qt_ave=exp(-kappa_triblock*(w_ave[0]*f[0]+w_ave[1]*f[1]+w_ave[2]*f[2]));
      Qd_ave=exp(-kappa_diblock*(w_ave[3]*f[3]+w_ave[4]*f[4]));
      Qh_ave=exp(-kappa_homopolymer*w_ave[5]);
      
      p_ave[0]=act_t*Qt_ave*f[0];
      p_ave[1]=act_t*Qt_ave*f[1];
      p_ave[2]=act_t*Qt_ave*f[2];
      p_ave[3]=act_d*Qd_ave*f[3];
      p_ave[4]=act_d*Qd_ave*f[4];
      p_ave[5]=act_h*Qh_ave;

      for(ii=0;ii<ChainType;ii++){
	del_w_ave[ii]=0.0;
	for(jj=0;jj<ChainType;jj++){  
	  del_w_ave[ii]+=chiMatrix[ii][jj]*p_ave[jj];
	}
	del_w_ave[ii]+=eta_ave;
	del_w_ave[ii]-=w_ave[ii];
      }

      dp=1.0-(p_ave[0]+p_ave[1]+p_ave[2]+p_ave[3]+p_ave[4]+p_ave[5]);
      dw=abs(del_w_ave[0]+del_w_ave[1]+del_w_ave[2]+del_w_ave[3]+del_w_ave[4]+del_w_ave[5])/(double)ChainType;

      for(ii=0;ii<ChainType;ii++){
	//w_ave[ii]+=epsilon_w*del_w_ave[ii];//-epsilon_phi*dp;
	w_ave[ii]+=0.005*del_w_ave[ii];
      }

      

      iter++;
    }while(iter<100000);
 
    //std::cout<<"iter= "<<iter<<"   dw= "<<dw<<"   tri= "<<p_ave[0]+p_ave[1]+p_ave[2]<<"   di= "<<p_ave[3]+p_ave[4]<<"   hom= "<<p_ave[5]<<" dp="<<dp<<std::endl;

    //std::cout<<"w0= "<<w_ave[0]<<"w1= "<<w_ave[1]<<"w2= "<<w_ave[2]<<"w3= "<<w_ave[3]<<"w4= "<<w_ave[4]<<"w5= "<<w_ave[5]<<std::endl;
    //std::cout<<"p0= "<<p_ave[0]<<"p1= "<<p_ave[1]<<"p2= "<<p_ave[2]<<"p3= "<<p_ave[3]<<"p4= "<<p_ave[4]<<"p5= "<<p_ave[5]<<std::endl;

    
    fE_homo=0.0;
    for(ii=0;ii<ChainType;ii++){
      for(jj=ii;jj<ChainType;jj++){  
	fE_homo+=p_ave[ii]*chiMatrix[ii][jj]*p_ave[jj];
      }
      fE_homo-=p_ave[ii]*w_ave[ii];
    }
    fE_homo-=((act_t*Qt_ave/kappa_triblock)+(act_d*Qd_ave/kappa_diblock)+(act_h*Qh_ave/kappa_homopolymer));
    
  }
  //std::cout<<fE_homo<<std::endl;
  
  //std::cin>>ii;
  return fE_homo;

};
