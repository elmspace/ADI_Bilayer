

reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/A_attracted_to_surface_data/MOD_main_delfE_vs_delV"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/A_attracted_to_surface_data/MOD_main_delfE_vs_delV"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel '{/Symbol D}V'  font "Times,32"
set ylabel 'f_{/Symbol \136}-f_{||}'  font "Times,32"

set key at 7.0,-0.12font "Times,22" spacing 2.2



set xrange [0.0: 20.0]
#set yrange [-0.14:0.07]
set ytics 0.04

set pointsize 2

f(x) = 0.0

plot f(x) w l notitle " " lc -1 lw 5,\
path_to_file."/MOD_main_delfE_vs_delV_PA_000.dat" using 1:($4-$3) title "PA=0.000" w lp lw 5 pt 6 lc -1,\
path_to_file."/MOD_main_delfE_vs_delV_PA_001.dat" using 1:($4-$3) title "PA=0.001" w lp lw 5 pt 8 lc -1,\
path_to_file."/MOD_main_delfE_vs_delV_PA_002.dat" using 1:($4-$3) title "PA=0.002" w lp lw 5 pt 4 lc -1



