%% Initializing the motor parameters.

% Terminal resistance. [Ohm]
R = 10.1;

% Terminal inductance. [H]
L = 2.04/1000;

% Friction constant. [Nm.s]
Kf = 0;

% Rotor inertia. [Kg/m^2]
J = 1.39e-6;

% Torque constant. [N.m/A]
Kt = 15.7e-3/(1.19);

% Back-emf constant. Same numerical value as the torque constant for DC and BLDCs
% [probably V/(rad/s)]
% Source: http://electronics.stackexchange.com/questions/33315/understanding-motor-constants-kt-and-kemf-for-comparing-brushless-dc-motors
Ke = Kt;

%% Creating the state-space model.

% state vector: [ i ; w_m ; theta_m ]
%     i:       current
%     w_m:     angular speed
%     theta_m: angular position
%     
% input vector: [V_s ; T_l]
%     V_s: DC-source voltage
%     T_l: Load torque
%
% output vector: [ i ; w_m ; theta_m ; T_e ]

A = [-R/L -Ke/L 0 ; Kt/J -Kf/J 0 ; 0 1 0];
B = [1/L 0 ; 0 -1/J ; 0 0];
C = [1 0 0 ; 0 1 0 ; 0 0 1 ; Kt 0 0];
D = zeros(4,2);

