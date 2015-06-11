reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV.dat"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




set xlabel '{/Symbol D}V'  font "Times,32"
set ylabel 'f_{/Symbol \136}-f_{||}'  font "Times,32"

set key at 7.0,-0.07font "Times,22" spacing 2.2



set xrange [0.0: 17.5]
set yrange [-0.14:0.07]
set ytics 0.04

set pointsize 2

f(x) = 0.0


plot f(x) w l notitle " " lc -1 lw 5,\
path_to_file  using 1:($4-$3) title "Per" w lp lw 4 pt 6,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/B_attracted_to_surface_data/MOD_main_delfE_vs_delV_BS/MOD_main_delfE_vs_delV_PA_001.dat" using 1:($4-$3) title "PA=0.001" w lp lw 5 pt 8 lc -1



pause(-1)

