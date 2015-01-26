A = [1.2 -3.7 ; 2.2 -1.5];
B = [0.33 1.1 ; -2 0.5];
C = [1 0];
D = [0 0];
Ahat = A+(rand(size(A))-0.5)*1;
Bhat = B+(rand(size(B))-0.5)*1;
L = place(Ahat',C',[-6,-5]);
L = L';