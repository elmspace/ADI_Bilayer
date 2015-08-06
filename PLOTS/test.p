reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Resolution/"
#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/"

set autoscale
unset key

f(x)=0.0414

set pointsize 2

#set xr [0.0 : 20.0]
#set yr [0.0 : 40.0]

a=4.3
b=4.3**3 * 3.14 * 2.0


plot path."Resolution.dat" using 1:2 w lp lc 1 pt 6


pause(-1)

