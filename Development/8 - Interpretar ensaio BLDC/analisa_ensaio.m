% Analisa um ensaio do motor BLDC

% Para rodar esse script, declare uma variável chamada filename, que recebe
% a string do nome do arquivo csv onde os dados do ensaio estarão.
% ex: 
filename = 'scope_7.csv';

% Lê o csv do ensaio.
[time, PWM, Hall1, Hall2, Hall3] = importfile(filename); 
time = time - time(1); 

step_size = time(2) - time(1);
final_time = time(size(time,1)) + step_size;

% Utilizando um modelo simulink, calcula a velocidade em cada instante com
% base nos sensores hall.
load_system('calcula_velocidade');
simout = sim('calcula_velocidade','SaveOutput','on');
yout = simout.get('yout');

% Cria uma structure com todos os valores importantes do ensaio.
%ensaio.time = time;
ensaio.time = time;
ensaio.PWM = PWM;
ensaio.Hall1 = Hall1;
ensaio.Hall2 = Hall2;
ensaio.Hall3 = Hall3;
ensaio.angular_velocity = yout(:,1);
ensaio.angular_position = yout(:,2);

% Limpa.
clear filename simout w theta Hall1 Hall2 Hall3 PWM time yout;

