


reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/B_attracted_to_surface_data/MOD_main_Vcritical_vs_PA"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_PA"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel 'P_A'  font "Times,32"
set ylabel '{/Symbol D}V_c'  font "Times,32"

set key at 0.0009,6.5 font "Times,22" spacing 2.2

set xrange [0.0: 0.003]
#set yrange [-0.2:0.06]

set ytics 2
set xtics 0.001

set pointsize 2

f(x) = 0.0

plot path_to_file."/MOD_main_Vcritical_vs_PA_xBI_0.dat" using 2:1 title "{/Symbol c}_{BI}=0" w lp lw 5 pt 2 lc -1,\
path_to_file."/MOD_main_Vcritical_vs_PA_xBI_50.dat" using 2:1 title "{/Symbol c}_{BI}=50" w lp lw 5 pt 4 lc -1,\
path_to_file."/MOD_main_Vcritical_vs_PA_xBI_100.dat" using 2:1 title "{/Symbol c}_{BI}=100" w lp lw 5 pt 6lc -1,\
path_to_file."/MOD_main_Vcritical_vs_PA_xBI_150.dat" using 2:1 title "{/Symbol c}_{BI}=150" w lp lw 5 pt 8 lc -1,\
path_to_file."/MOD_main_Vcritical_vs_PA_xBI_200.dat" using 2:1 title "{/Symbol c}_{BI}=200" w lp lw 5 pt 10 lc -1




