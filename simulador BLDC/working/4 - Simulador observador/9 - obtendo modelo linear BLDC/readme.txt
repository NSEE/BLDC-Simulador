Fiz a linearização do motor

	- Supondo uma função de transferência do tipo G/(Ts+1) obtive o modelo salvo em "motor_linearizado_sem_zeros"
		- Dentro do arquivo tem a função de transferência e o espaço de estados correspondente
		  (onde os estados são posição, velocidade e aceleração e a saída é velocidade angular); 
		  dedução da transformação na pág 41 do meu caderno de rascunho.
		- Dentro do arquivo "discretizacao_modelo_linear sem zeros.nb" tem a versão discretizada
		  simbolicamente no Mathematica.
	- Supondo uma função de transferência do tipo (as+b)/(s^2+cs+d) obtive o "motor_linearizado"
		- O problema aqui é que não sei como passar essa tf para um espaço de estados que um dos
		  estados seja a posição (que é o que eu meço)

