reset

path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/" # Elmspace
path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/" #Landua

path2= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/Tests/Fig3_Review_Paper/" #Landua


set xr [0.0 : 20.0]
#set yr [0 : 300]
unset key

#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
f1(x) = a1*x + b1 
fit [0.0 : 30.0] f1(x) path."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5/$1) via a1, b1
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f2
a2 = 0.0
b2 = 0.0
f2(x) = a2*x + b2 
fit [0.0 : 30.0] f2(x) path2."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5/$1) via a2, b2
#++++++++++++++++++++++++++++++++++++


plot path."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
path2."Mod1_Results.dat" using 1:(2*(($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
f1(x),\
f2(x)


#pause(-1)

