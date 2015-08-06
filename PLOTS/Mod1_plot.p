reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/"
#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/"


unset key

f(x)=0.0

plot path."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6


pause(-1)

