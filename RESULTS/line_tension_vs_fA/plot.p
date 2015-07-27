reset

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

path1 = "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/line_tension_vs_fA/AB_sigma_vs_fA.dat"

unset key
set pointsize 2

#set xr [0.0 : 20.0]
#set yr [0.0 : 100.0]

#set ylabel 'F^D/R'  font ",22"
#set xlabel 'R'  font ",22"


plot path1 using 1:2 w lp lc 1 pt 6,\
 path1 using 1:3 w lp lc 3 pt 8

