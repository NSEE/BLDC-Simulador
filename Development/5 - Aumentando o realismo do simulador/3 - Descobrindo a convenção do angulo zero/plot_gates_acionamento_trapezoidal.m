h1 = subplot(3,1,1);
plot(tout*360,gates(:,1),'LineWidth',4); grid; axis([0 360 -1 1]);
h2 = subplot(3,1,2);
plot(tout*360,gates(:,2),'LineWidth',4); grid; axis([0 360 -1 1]);
h3 = subplot(3,1,3);
plot(tout*360,gates(:,3),'LineWidth',4); grid; axis([0 360 -1 1]);

set(h1,'XTick',[0,60,120,180,240,300,360]);
set(h2,'XTick',[0,60,120,180,240,300,360]);
set(h3,'XTick',[0,60,120,180,240,300,360]);

