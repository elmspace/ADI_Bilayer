reset
unset multiplot

set term postscript enhanced color
set output "~/Desktop/fE.ps"

path= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/FARM/mu_4p4/RESULTS/Mod1_Results.dat"

set fit logfile '/dev/null'



unset key
set pointsize 2

set xr [0.0 : 17.0]
#set yr [0.0 : 100.0]

set ylabel 'F^D/R'  font ",22"
set xlabel 'R'  font ",22"

set multiplot
set origin 0.0,0.0
set size 1.0,1.0


#++++++++++++++++++++++++++++++++++++ f1
a2 = 0.0
b2 = 0.0
f2(x) = a2*x + b2
fit [0.0 : 30.0] f2(x) path using  ($1-4.0):((($2-$3)/($4))*$5/$1) via a2, b2
#++++++++++++++++++++++++++++++++++++

plot f2(x) w l lc -1,\
path using ($1-4.0):((($2-$3)/($4))*$5/$1) w lp lc 1 pt 6


set size 0.4,0.4
set origin 0.58,0.15

set xr [0.0 : 17.0]
set yr [0.0 : 50.0]
set xtics 5
set ytics 20

set ylabel 'F^D'  font ",12"
unset xlabel


#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
c1 = 0.0
f1(x) = a1*x**2 + b1*x + c1
fit [0.0 : 30.0] f1(x) path using ($1-4.0):((($2-$3)/($4))*$5) via a1, b1, c1
#++++++++++++++++++++++++++++++++++++

plot f1(x) w l lc -1,\
path using ($1-4.0):((($2-$3)/($4))*$5) w lp lc 1 pt 6

unset multiplot
