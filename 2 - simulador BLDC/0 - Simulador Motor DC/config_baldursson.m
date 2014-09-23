%% Initializing the motor parameters.

% Terminal resistance phase to phase. [Ohm]
R = 12.5;

% Terminal inductance phase to phase. [H]
L = 0.091e-3;

% Friction constant (Assumed value by S.Baldursson). [Nm.s]
Kf = 1.38e-8;

% Rotor inertia. 0.005[g.cm^2] -> 0.05 [Kg/m^2]
J = 0.05;

% Torque constant. [N.m/A]
Kt = 1.05e-3;

% Back-emf constant. Same numerical value as the torque constant for BLDCs
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

