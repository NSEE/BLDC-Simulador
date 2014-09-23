% Creating a low pass filter. Cutoff frequency at fc Hz.
fc = 60;
Tau = 1/(2*pi*fc);
G = tf(1,[Tau 1]);

% Converting it into a discrete low pass filter, sample time Ts.
Ts = 0.001;
Gd = c2d(G,Ts);