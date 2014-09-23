% Creating the plant to be controlled.
G = tf(1,[1 10]);

% Creating the continuous-time controller.
C = pid(19.5284,195.2845);

% Validating the continuous-time controller.
% subplot(1,2,1);
% step(G);
% title('Plant step response');
% axis([0 1 0 1]);
% subplot(1,2,2);
% step(feedback(G*C,1));
% title('Controled step response');
% axis([0 1 0 1]);

% Creating the discrete-time controller.
Ts = 0.001;
Cd = c2d(C,Ts);

% Creating the discrete-time plant.
Gd = c2d(G,Ts);