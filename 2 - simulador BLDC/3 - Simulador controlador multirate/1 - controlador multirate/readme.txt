Desenvolvi um controlador discreto que pode mudar de Ts durante a
execução da simulação. Esse simulador atualiza sua saída quando "clock"
estiver em nível lógico alto (já calcula automaticamente o tempo passado
e atualiza os ganhos do controlador).

Para validar forcei o Ts do meu bloco ser constante e comparei com o 
controlador discreto do próprio simulink.