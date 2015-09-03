reset

p1= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/fA_0p7/1.dat"
p2= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/fA_0p7/2.dat"
p3= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/fA_0p7/3.dat"
p4= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/fA_0p7/4.dat"
p5= "/home/ash/Desktop/SCFT_CODES/ADI_Bilayer/Test/main/RESULTS/fA_0p7/5.dat"


set xr [9.0 : 25.0]
#set yr [-16 : 16]
unset key

#++++++++++++++++++++++++++++++++++++ f1
a1 = 0.0
b1 = 0.0
c1 = 0.0
f1(x) = a1*x**2 + b1*x + c1
fit [0.0 : 30.0] f1(x) p1 using 1:((($2-$3)/$4)*$5) via a1, b1, c1
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f2
a2 = 0.0
b2 = 0.0
c2 = 0.0
f2(x) = a2*x**2 + b2*x + c2
fit [0.0 : 30.0] f2(x) p2 using 1:((($2-$3)/$4)*$5) via a2, b2, c2
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f3
a3 = 0.0
b3 = 0.0
c3 = 0.0
f3(x) = a3*x**2 + b3*x + c3
fit [0.0 : 30.0] f3(x) p3 using 1:((($2-$3)/$4)*$5) via a3, b3, c3
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f4
a4 = 0.0
b4 = 0.0
c4 = 0.0
f4(x) = a4*x**2 + b4*x + c4
fit [0.0 : 30.0] f4(x) p4 using 1:((($2-$3)/$4)*$5) via a4, b4, c4
#++++++++++++++++++++++++++++++++++++

#++++++++++++++++++++++++++++++++++++ f5
a5 = 0.0
b5 = 0.0
c5 = 0.0
f5(x) = a5*x**2 + b5*2 + c5
fit [0.0 : 30.0] f5(x) p5 using 1:((($2-$3)/$4)*$5) via a5, b5, c5
#++++++++++++++++++++++++++++++++++++


plot  p1 using 1:((($2-$3)/$4)*$5) w lp lc 1 pt 6,\
p2 using 1:((($2-$3)/$4)*$5) w lp lc 1 pt 6,\
p3 using 1:((($2-$3)/$4)*$5) w lp lc 1 pt 6,\
p4 using 1:((($2-$3)/$4)*$5) w lp lc 1 pt 6,\
p5 using 1:((($2-$3)/$4)*$5) w lp lc 1 pt 6,\
f1(x) lc 1,\
f2(x) lc 2,\
f3(x) lc 3,\
f4(x) lc 4,\
f5(x) lc 5


pause(-1)

