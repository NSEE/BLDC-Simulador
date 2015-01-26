% 
% subplot(3,1,1); 
% plot(tout,simx_hat(:,1));
% hold on; 
% plot(tout,simx,'r'); 
% subplot(3,1,2); 
% plot(simL(3:size(simL),1)); 
% subplot(3,1,3); 
% plot(1./deltaT(3:100707));

% figure;
% plot(tout,simx_hat(:,1));
% hold on; 
% plot(tout,simx,'r'); 
% axis([0 10 -450 700]);
% plot(tout,trigger_sens*100,'r')
% plot(tout,trigger*200,'k');


obsv = zeros(size(simL));
obsv(find(trigger==1),:) = simL(find(trigger==1),:);
obsv(find(trigger_sens==1),:) = simL(find(trigger_sens==1),:);


figure;
plot(tout,simx_hat(:,1));
hold on; 
plot(tout,simx,'r'); 
axis([0 10 -450 700]);
plot(tout,trigger_sens*100,'r');
%plot(tout,obsv(:,1)*10,'g');
plot(tout,trigger*200,'k');