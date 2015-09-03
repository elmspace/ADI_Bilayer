reset

path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/fA_0p7/"
path1= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/"

set xr [0.0 : 30.0]
#set yr [-16 : 16]
unset key

#++++++++++++++++++++++++++++++++++++ f1
#a1 = 0.0
#b1 = 0.0
#c1 = 0.0 
#f1(x) = a1*x**2 + b1*x + c1
#fit [0.0 : 30.0] f1(x) path."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5) via a1, b1, c1
#++++++++++++++++++++++++++++++++++++

plot  path1."Mod1_Results.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 3 pt 6,\
path."1.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
path."2.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
path."3.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
path."4.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6,\
path."5.dat" using 1:((($2-$3)/$4)*$5/$1) w lp lc 1 pt 6



pause(-1)

