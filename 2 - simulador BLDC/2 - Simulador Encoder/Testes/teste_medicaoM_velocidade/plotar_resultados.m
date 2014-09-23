load resultados.mat;

% Plota exata x medida.
subplot(2,1,1);
plot(resultados.vel_exata.Time,resultados.vel_exata.Data);
hold;
plot(resultados.vel_medida.Time,resultados.vel_medida.Data,'r');
grid minor;
title('Medição de velocidade M');
legend('Velocidade exata','Velocidade medida');

% Plota erro percentual.
subplot(2,1,2);
plot(resultados.vel_exata.Time, 100*abs(resultados.vel_exata.Data-resultados.vel_medida.Data)./resultados.vel_exata.Data );
grid minor;
axis([0 2 0 30]);
title('Erro na medição');
legend('100*abs(exata-medida)/exata')
