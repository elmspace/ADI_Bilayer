/*
In this function, we will initialize the omega fields
*/
void setOmega( ){

  int i, j, chain;

    for(i=0;i<NBox;i++){
      for(j=0;j<NBox;j++){
	w[3][i][j]=-0.1*cos(2.0*Pi*j/NBox);
	//w[4][i][j]=0.1*cos(2.0*Pi*j/NBox);
      }
    }

    return;

};
