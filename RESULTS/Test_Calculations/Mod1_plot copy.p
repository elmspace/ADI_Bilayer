reset

set term postscript enhanced color
set output "~/Desktop/fE.ps"

file1= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Mod1/Mod1_fA_0p4_mu4p4.dat"
file2= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Mod1/Mod1_fA_0p4_mu4p5.dat"
file3= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Mod1/Mod1_fA_0p4_mu4p6.dat"
file4= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Mod1/Mod1_fA_0p4_mu4p7.dat"
file5= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Mod1/Mod1_fA_0p4_mu4p8.dat"
file6= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/Test_Calculations/Mod1/Mod1_fA_0p4_mu4p9.dat"


set pointsize 2

set xr [0.0 : 30.0]
#set yr [-80.0 : 120.0]

set key t c font ",18" spacing 1.5

set xlabel 'R'  font ",32" offset 0,-1
set ylabel 'F^D'  font ",32"

#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
c1 = 0.0
f1(x) = a1*x**2 + b1*x + c1
fit [0.0 : 30.0] f1(x) file1 using 2:(((($3-$4)/$5)*$6)) via a1, b1, c1
#++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++ f2
a2 = 0.0
b2 = 0.0
c2 = 0.0
f2(x) = a2*x**2 + b2*x + c2
fit [0.0 : 30.0] f2(x) file2 using 2:(((($3-$4)/$5)*$6)) via a2, b2, c2
#++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++ f3
a3 = 0.0
b3 = 0.0
c3 = 0.0
f3(x) = a3*x**2 + b3*x + c3
fit [0.0 : 30.0] f3(x) file3 using 2:(((($3-$4)/$5)*$6)) via a3, b3, c3
#++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++ f4
a4 = 0.0
b4 = 0.0
c4 = 0.0
f4(x) = a4*x**2 + b4*x + c4
fit [0.0 : 30.0] f4(x) file4 using 2:(((($3-$4)/$5)*$6)) via a4, b4, c4
#++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++ f5
a5 = 0.0
b5 = 0.0
c5 = 0.0
f5(x) = a5*x**2 + b5*x + c5
fit [0.0 : 30.0] f5(x) file5 using 2:(((($3-$4)/$5)*$6)) via a5, b5, c5
#++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++ f6
a6 = 0.0
b6 = 0.0
c6 = 0.0
f6(x) = a6*x**2 + b6*x + c6
fit [0.0 : 30.0] f6(x) file6 using 2:(((($3-$4)/$5)*$6)) via a6, b6, c6
#++++++++++++++++++++++++++++++++++++



plot f1(x) w l notitle lc -1 lt 1 lw 4,\
f2(x) w l notitle lc -1 lt 1 lw 4,\
f3(x) w l notitle lc -1 lt 1 lw 4,\
f4(x) w l notitle lc -1 lt 1 lw 4,\
f5(x) w l notitle lc -1 lt 1 lw 4,\
f6(x) w l notitle lc -1 lt 1 lw 4,\
file1 using 2:(((($3-$4)/$5)*$6)) w p title "{/Symbol m}=4.4" lc -1 pt 7,\
file2 using 2:(((($3-$4)/$5)*$6)) w p title "{/Symbol m}=4.5" lc -1 pt 8,\
file3 using 2:(((($3-$4)/$5)*$6)) w p title "{/Symbol m}=4.6" lc -1 pt 9,\
file4 using 2:(((($3-$4)/$5)*$6)) w p title "{/Symbol m}=4.7" lc -1 pt 4,\
file5 using 2:(((($3-$4)/$5)*$6)) w p title "{/Symbol m}=4.8" lc -1 pt 5,\
file6 using 2:(((($3-$4)/$5)*$6)) w p title "{/Symbol m}=4.9" lc -1 pt 6



pause(-1)
