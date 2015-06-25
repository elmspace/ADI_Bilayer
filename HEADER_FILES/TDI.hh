/*
* tridiagonal: Thomas' algorithm implementation
*Inputs: a,b,c are L,D,U vectors respectively
*        d is coefficient vector; is overwritten with solution vector
*        len is length of b et d
*Outputs: Returns 0 (if you want to signal an error at some point, return something else)
*         As above, d is overwritten with answer vector.
*         a,b also modified
*Note: For simplicity's sake b is overwritten with successive denominators (see Method above);
*      it isn't hard to change this if you so wish
*Note 2: We don't check for diagonal dominance, etc.; 
*        this is not guaranteed stable
*/
int TDI (double *c, double *b, double *a, double *d, int len) // Upper, Middle, Lower, sol/input, length
{
    int i;
 
   /*Forward sweep*/
    *a /= *b;
    for(i=1;i<len-1;i++)
    {
        b[i] -= (a[i-1]*c[i-1]);
        a[i] /=b[i]; 
    }
    b[len-1] -= (a[len-2]*c[len-2]); 
 
    for(i=1;i<len;i++)
        d[i] -= (d[i-1]*a[i-1]);
    d[len-1] /= b[len-1];
 
    /*Backward sweep*/
    for(i=len-2;i>=0;i--)
    {
        d[i] -= (d[i+1]*c[i]);
        d[i] /= b[i];
    }
    return 0;
    
 
}
