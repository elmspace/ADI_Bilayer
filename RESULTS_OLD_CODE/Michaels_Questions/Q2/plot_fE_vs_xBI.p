reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS_OLD_CODE/Michaels_Questions/Q2/"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

set xlabel '{/Symbol c}_{BI}'  font "Times,32"
set ylabel 'f_{/Symbol \136} and f_{||}'  font "Times,32"

set key b r font "Times,22" spacing 2.2

set xr [0.0 : 190]

set pointsize 2

plot path_to_file."MOD_main_fE_vs_xBI_Per.dat"  using 1:($3/3.43055) title "Per" w lp lw 2 pt 6 lc -1,\
path_to_file."MOD_main_fE_vs_xBI_Par.dat"  using 1:($3/3.38773) title "Par" w lp lw 2 pt 8 lc -1



pause(-1)

