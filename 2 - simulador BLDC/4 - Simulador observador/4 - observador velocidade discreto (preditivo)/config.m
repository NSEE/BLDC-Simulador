Kv = 0.2;

A = [-Kv 0 ; 1 0];
B = [10 ; 0];
C = [0 1];
D = [0];

Ahat = [-0.1 0 ; 1 0];
Bhat = [10 ; 0];
sys = ss(Ahat,Bhat,C,D);
Ts = 0.02;
sysd = c2d(sys,Ts);

Aobs = sysd.A;
Bobs = sysd.B;
Cobs = sysd.C;
Dobs = sysd.D;

L = place(Aobs',Cobs',[0.6 0.5]);
L = L';
