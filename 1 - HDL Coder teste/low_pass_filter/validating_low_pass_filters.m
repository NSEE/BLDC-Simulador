%% Creating a low pass filter. Cutoff frequency at 60Hz.
fc = 60;
Tau = 1/(2*pi*fc);
G = tf(1,[Tau 1]);

%% Testing the continuous low pass filter.
subplot(2,2,1);

% 300Hz sine wave input.
f_sin = 300;
t = 0:3/f_sin/1000:3/f_sin;
u1 = sin(f_sin*2*pi*t);
lsim(G,u1,t);
title('300Hz');

% 120Hz sine wave input.
f_sin = 120;
t = 0:3/f_sin/1000:3/f_sin;
u2 = sin(f_sin*2*pi*t);
subplot(2,2,2);
lsim(G,u2,t);
title('120Hz');

% 60Hz sine wave input.
f_sin = 60;
t = 0:3/f_sin/1000:3/f_sin;
u3 = sin(f_sin*2*pi*t);
subplot(2,2,3);
lsim(G,u3,t);
title('60Hz');

% 60Hz sine wave + 300Hz sine wave input.
f_sin = 60;
t = 0:3/f_sin/1000:3/f_sin;
u4 = sin(f_sin*2*pi*t) + sin(300*2*pi*t);
subplot(2,2,4);
lsim(G,u4,t);
title('60Hz + 500Hz');
axis([0 3/f_sin -1 1]);


%% Converting it into a discrete low pass filter.
Ts = 0.001;
Gd = c2d(G,Ts);

%% Testing the discrete low pass filter.
figure;
subplot(2,2,1);

% 300Hz sine wave input.
f_sin = 300;
t = 0:Ts:3/f_sin;
u1 = sin(f_sin*2*pi*t);
lsim(G,u1,t);
title('300Hz');

% 120Hz sine wave input.
f_sin = 120;
t = 0:Ts:3/f_sin;
u2 = sin(f_sin*2*pi*t);
subplot(2,2,2);
lsim(G,u2,t);
title('120Hz');

% 60Hz sine wave input.
f_sin = 60;
t = 0:Ts:3/f_sin;
u3 = sin(f_sin*2*pi*t);
subplot(2,2,3);
lsim(G,u3,t);
title('60Hz');

% 60Hz sine wave + 300Hz sine wave input.
f_sin = 60;
t = 0:Ts:3/f_sin;
u4 = sin(f_sin*2*pi*t) + sin(300*2*pi*t);
subplot(2,2,4);
lsim(G,u4,t);
title('60Hz + 500Hz');
axis([0 3/f_sin -1 1]);


