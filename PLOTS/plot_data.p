reset
set key b l

f(x) = 0.0



#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV.dat"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_delfE_vs_delV.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






#
#b = 0.0
#m = 0.0
#f(x) = m*x + b
#fit [3.5 : 4.0] f(x) path_to_file using (abs($2)):4 via b, m

#c = 0.0
#n = 0.0
#g(x) = n*x + c
#fit  [7.0 : 8.5] g(x) path_to_file using (abs($2)):4 via c, n



set yr [0.0 : 0.1]


plot path_to_file  using 1:($4-$3) title "Per" w lp lw 2 pt 8,\
path_to_file  using 1:($4-$3) title "Mix" w lp lw 2 pt 8

#g(x) title "g" lw 3,\
#f(x) title "f" lw 3


pause(-1)


reset
set key b l

f(x) = 0.0

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
#path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat"
# Landau
path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/MOD_main_Vcritical_vs_mu_all_Phases.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

plot path_to_file using 2:($4-$5) title "Per" w lp lw 2 pt 8

