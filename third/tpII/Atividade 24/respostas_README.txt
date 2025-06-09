## 
1. Como o padrão Strategy facilita a adição de um novo método de pagamento sem modificar a lógica principal do sistema?

O padrão Strategy permite encapsular o comportamento de cada método de pagamento em uma classe separada. Assim, ao adicionar um novo método, como por exemplo Boleto ou Criptomoeda, basta criar uma nova classe que implementa a interface PaymentStrategy.
Isso evita alterações na lógica central (PaymentProcessor), seguindo o princípio aberto/fechado (Open/Closed Principle): o sistema está aberto para extensão e fechado para modificação.

##
2. Como o método set_strategy ajuda a tornar o sistema mais flexível?

O método set_strategy permite mudar dinamicamente o comportamento do objeto de acordo com a necessidade.
Isso torna o sistema mais flexível, pois o cliente pode escolher a estratégia de pagamento em tempo de execução, sem depender de estruturas condicionais como if ou switch.
Essa abordagem facilita o reuso e a manutenção do código.

## 
3. Qual é a principal vantagem de encapsular cada forma de pagamento em uma classe separada?

Encapsular cada método de pagamento em uma classe própria promove a separação de responsabilidades.
Cada classe é responsável por um único comportamento e pode ser modificada, testada ou reutilizada de forma isolada.
Isso melhora a legibilidade, manutenção e evita efeitos colaterais em outros módulos do sistema.