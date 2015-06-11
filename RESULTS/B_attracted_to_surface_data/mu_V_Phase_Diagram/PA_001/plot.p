reset

unset key



#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/B_attracted_to_surface_data/mu_V_Phase_Diagram/PA_001/data_PA_001.dat"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/RESULTS/B_Surf/PA_001/MOD_main_Vcritical_vs_mu.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






set term postscript enhanced color
set output "~/Desktop/fE.ps"

set xlabel '{/Symbol m'  font "Times,40"
set ylabel '{/Symbol D}V'  font "Times,40"


set xr [0.0 : 7.0]
set yr [0.0 : 30.0]


set label "Par" at 4,10 font "Times,40"
set label "Per" at 1.1,23 font "Times,40"
set label "P-Mix" at 2.5,28 font "Times,40"
set label "Mix" at 5.6,25 font "Times,40"

set arrow 1 from 3.8,27 to 4.5,25


plot path_to_file using (abs($2)):1 smooth bezier lw 5 lc -1

