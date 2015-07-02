reset

path= "/Users/ashkandehghan/Desktop/SCFT_CODES/ADI_Bilayer/PHI/"


set pm3d
set iso 100
set samp 100
set palette model RGB
set dgrid3d 32,32,2
set pm3d flush begin ftriangles scansforward interpolate 10,5
   
unset key
unset sur
set hidden3d
set view map 
set autoscale
set size square

   splot path."phi2D.dat" using 1:2:($6+$7)
