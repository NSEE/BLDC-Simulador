A = [1.2 -3.7 ; 2.2 -1.5];
B = [0.33 1.1 ; -2 0.5];
C = [1 0];
D = [0 0];

Ahat = A+(rand(size(A))-0.5)*0.5;
Bhat = B+(rand(size(B))-0.5)*0.5;

Ts = 0.03;
sys = ss(Ahat,Bhat,C,D);
sysd = c2d(sys,Ts);

L = place(sysd.a',sysd.c',[0.5,0.4]);
L = L';