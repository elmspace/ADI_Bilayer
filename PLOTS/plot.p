


reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
#path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi2D.dat"
# Landau
path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm2/PHI/phi2D.dat"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#set term postscript enhanced color
#set output "~/Desktop/fE.ps"

set pm3d
set iso 100
set samp 100
set palette model RGB
set dgrid3d 32,32,1
#set size square
unset border
unset xtics
unset ytics
#unset colorbox
set pm3d flush begin ftriangles scansforward interpolate 10,5

set xlabel 'Electrode +'  font ",22"
set title 'Electrode -'  font ",22"
   
   unset key
   unset sur
   set hidden3d
   set view map 
   set autoscale
   set size square
   
   splot path_to_file using 2:1:4






pause(-1)

   
reset

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Mac
path_to_file = "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/"
# Landau
#path_to_file = "/1/home/dehgha2/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/"
##++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   
   
#set term postscript enhanced color
#set output "~/Desktop/fE.ps"
   
unset key
unset y2tics
   set ytics 0.0004

set xr [0.0 : 7.8]


set xlabel 'L'  font ",22"
set ylabel '{/Symbol f}_+   {/Symbol f}_-'  font ",22"

   


   f(x)=0.0
   
plot f(x) w l lt -1,\
   path_to_file."phi1Dx.dat" using 1:2 axes x1y2 w l lw 1 lt 1 lc 1,\
   path_to_file."phi1Dx.dat" using 1:3 axes x1y2 w l lw 1 lt 1 lc 2,\
   path_to_file."phi1Dx.dat" using 1:4 axes x1y1 w l lw 5 lt 1 lc 3,\
   path_to_file."phi1Dx.dat" using 1:5 axes x1y1 w l lw 5 lt 1 lc 4

pause(-1)




reset
unset key
unset y2tics

# set xr [0.0 : 7.8]
# set yr [-0.001 : 0.0015]

   f(x)=0.0
   
plot f(x) w l lt -1,\
   "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dy.dat" using 1:2 axes x1y2 w lp lw 3 lt 1,\
"/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dy.dat" using 1:3 axes x1y2 w lp lw 3 lt 2,\
   "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dy.dat" using 1:4 axes x1y1 w lp lw 3 lt 3,\
  "/Users/ashkandehghan/Desktop/SCFT_CODES/AB_Charged_ThinFilm/PHI/phi1Dy.dat" using 1:5 axes x1y1 w lp lw 3 lt 4
