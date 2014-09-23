Criei um siulador do encoder que não precisa simular cada pulso gerado pelos
sensores ópticos. Apesar de ser bem mais rápido de simular e não apresentar
alguns problemas por o step size ser muito grande, não deve ser utilizado
para alimentar os métodos T e M/T para cálculo de velocidade (exatamente
por ele não simular todos os pulsos dos sensores ópticos, e esses métodos
pressuporem que esses pulsos sempre serão simulados).