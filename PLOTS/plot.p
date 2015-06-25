reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/PHI/"


set autoscale
unset key


plot   path."phi_r.dat" using 1:2 w lp,\
path."phi_r.dat" using 1:3 w lp,\
path."phi_r.dat" using 1:4 w lp,\
path."phi_r.dat" using 1:5 w lp,\
path."phi_r.dat" using 1:6 w lp,\
path."phi_r.dat" using 1:7 w lp


pause(-1)


reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/PHI/"


set autoscale
unset key


plot   path."phi_z.dat" using 1:2 w lp,\
path."phi_z.dat" using 1:3 w lp,\
path."phi_z.dat" using 1:4 w lp,\
path."phi_z.dat" using 1:5 w lp,\
path."phi_z.dat" using 1:6 w lp,\
path."phi_z.dat" using 1:7 w lp
