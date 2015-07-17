reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/RESULTS/SHARCNET/"


set autoscale
unset key

f(x)=0.0414

set pointsize 2

#set xr [0.0 : 20.0]
#set yr [0.0 : 20.0]

a=4.3
b=4.3**3 * 3.14 * 2.0

plot path."fE_vs_R_mu4p58_Po.dat" using 2:((($3-($4*$5))/$6)/$2) w lp lc 1 pt 6


pause(-1)


#plot path."Bi_Por_Ten.dat" using ($2/a):(($7-$3)/(b)) w lp lc 1 pt 6
#path."Bi_Por_NoTen.dat" using ($2/a):(($7-$3)/(b)) w lp lc 3 pt 4
