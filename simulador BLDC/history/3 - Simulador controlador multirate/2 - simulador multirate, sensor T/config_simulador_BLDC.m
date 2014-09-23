%%Inicialização das variáveis do motor
%Maxon flat motor EC 32 flat - 339260 - 12v
R=10.1/2; %Resistência por fase em Ohm
L=2.04/2000; %Indutância por fase em Henry
P=8; %Número de polos
Kt=15.7e-3/(1.19); % Constante de torque do motor em Nm/A
Kd=0; %Este valor não é dado no catálogo (atrito viscoso)
J=1.39e-6; %Inércia do rotor em kg.m^2
Ke=Kt; %Consta de força eletromotriz em V.s (Igualdade válida apenas para unidades no SI)