reset

path= "/1/home/dehgha2/Desktop/SCFT_CODES/ADI_Bilayer/ADI_Bilayer/RESULTS/Tests/fE.dat" #Landua


set autoscale
set key r c


plot path using 1:2 title "A" w lp,\
 path using 1:3 title "A" w lp
