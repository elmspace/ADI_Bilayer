% Program IsoSurface, run by typing run("./main.m")

% Clear all previous variables
clear all;
% Getting the coordiante variables from the data, and making them
% into the correct format, mesh
A=importdata('./xyz.dat');
%getting the concentration from the data file
B=importdata('./ABI.dat');

[X,Y,Z]=meshgrid(A(:,2),A(:,1),A(:,3));


% The size is used for the for loop
x_size=size(A(:,1),1);
y_size=size(A(:,2),1);
z_size=size(A(:,3),1);
% Dividing up the concentration values
VA=zeros(x_size,y_size,z_size);
VB=zeros(x_size,y_size,z_size);
VI=zeros(x_size,y_size,z_size);
VWall=zeros(x_size,y_size,z_size);
% Taking the concentration values and putting them into the correct
% format, mesh-format
ii=1;
for i=1:x_size,
    for j=1:y_size,
        for k=1:z_size,
            VA(i,j,k)=B(ii,1);
            VB(i,j,k)=B(ii,2);
            VI(i,j,k)=B(ii,3);
            VWall(i,j,k)=B(ii,4);
            ii=ii+1;
        end
    end
end
% clearing useless variables
clear i;
clear j;
clear k;
clear ii;
% Thres3old for the isosurf, 
cutA=0.5;
cutB=0.5;
cutI=0.35;
cutWall=5.0;


axis vis3d;
view([0,0,1]);
axis off;
daspect('mode');


% A    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pA = patch(isosurface(X,Y,Z,VA,cutA),'FaceColor','red','EdgeColor','none');
qA = patch(isocaps(X,Y,Z,VA,cutA),'FaceColor','red','EdgeColor', ...
         'none');
alpha(pA,1.0);
alpha(qA,1.0);
% B
% ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pB = patch(isosurface(X,Y,Z,VB,cutB),'FaceColor','green','EdgeColor','none');
qB = patch(isocaps(X,Y,Z,VB,cutB),'FaceColor','green','EdgeColor', ...
          'none');
alpha(pB,1.0);
alpha(qB,1.0);

% I
% ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pI = patch(isosurface(X,Y,Z,VI,cutI),'FaceColor','yellow','EdgeColor','none');
qI = patch(isocaps(X,Y,Z,VI,cutI),'FaceColor','yellow','EdgeColor', ...
          'none');
alpha(pI,0.4);
alpha(qI,0.4);


% Wall
% ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pWall = patch(isosurface(X,Y,Z,VWall,cutWall),'FaceColor','black','EdgeColor','none');
qWall = patch(isocaps(X,Y,Z,VWall,cutWall),'FaceColor','black','EdgeColor', ...
          'none');
alpha(pWall,1.0);
alpha(qWall,1.0);



