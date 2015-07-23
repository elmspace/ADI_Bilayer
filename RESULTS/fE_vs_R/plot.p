reset

#path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/fE_vs_Mu/"
#path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/fE_vs_Mu/"
path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/fE_vs_R/"

unset key

set pointsize 2

set xr [0.0 : 30.0]
set yr [0.0 : 40.0]

f(x)=0.0

plot f(x) w l lc -1,\
path."fE_vs_R_AB_Hom.dat" using 1:((($2-$3)/$4)*$5) w lp lc 1 pt 6
#path."fE_vs_R_ABA_Hom.dat" using 1:((($2-$3)/$4)*$5) w lp lc 3 pt 8


pause(-1)
