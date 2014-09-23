"encoder_M_T.slx" - O método T de velocidade tinha um BUG: ele assumia que os pulsos do encoder
sempre significavam que ele estava girando no sentido positivo. A versão
dessa pasta já está com esse bug arrumado.

"desacoplando_metodoT_do_encoder.slx" - Testes feitos para ver se o método T pode ser
devidamente desacoplado do encoder. Tudo indica que sim (apesar do comportamento dos
método T desacoplado e do método T acoplado não ser exatamente igual).