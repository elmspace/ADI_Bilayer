reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/"


set autoscale
unset key

f(x)=0.0414

set pointsize 2

set xr [0.0 : 100.0]

plot path."test2.dat" using ($1):2 w lp lc 1 pt 6,\
path."test2.dat" using ($1):3 w lp lc 1 pt 6

pause(-1)
