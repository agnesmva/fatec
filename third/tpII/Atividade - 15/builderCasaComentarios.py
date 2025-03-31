from abc import ABC, abstractmethod

# Classe abstrata que define a interface do Builder.
# Cada método representa uma etapa da construção da casa, garantindo que todas as casas sigam um mesmo processo de construção.
class ConstrutorCasa(ABC):
    
    @abstractmethod
    def construir_fundacao(self):
        pass  # Define que a implementação concreta precisa adicionar uma fundação à casa.

    @abstractmethod
    def construir_estrutura(self):
        pass  # Define que a estrutura da casa deve ser construída na implementação concreta.

    @abstractmethod
    def construir_telhado(self):
        pass  # Obriga a implementação de um telhado adequado.

    @abstractmethod
    def pintar_casa(self):
        pass  # Exige que a casa tenha uma pintura aplicada.

    @abstractmethod
    def mobiliar_casa(self):
        pass  # Garante que a casa seja mobiliada conforme o estilo definido.

    @abstractmethod
    def get_casa(self):
        pass  # Retorna o objeto final após todas as etapas da construção.

# Builder concreto para construir uma casa moderna.
class ConstrutorCasaModerna(ConstrutorCasa):
    def __init__(self):
        self.casa = Casa()  # Inicializa um novo objeto Casa.

    def construir_fundacao(self):
        self.casa.add('Fundação moderna')  # Adiciona uma fundação específica para casas modernas.

    def construir_estrutura(self):
        self.casa.add('Estrutura moderna com janelas amplas')  # Estrutura diferenciada com vidros.

    def construir_telhado(self):
        self.casa.add('Telhado plano')  # Estilo arquitetônico moderno.

    def pintar_casa(self):
        self.casa.add('Pintura branca')  # Cor padrão para casas modernas.

    def mobiliar_casa(self):
        self.casa.add('Móveis minimalistas')  # Decoração moderna e funcional.

    def get_casa(self):
        return self.casa  # Retorna a casa finalizada.

# Builder concreto para construir uma casa de campo.
class ConstrutorCasaDeCampo(ConstrutorCasa):
    def __init__(self):
        self.casa = Casa()  # Inicializa um novo objeto Casa.

    def construir_fundacao(self):
        self.casa.add('Fundação de pedra')  # Fundação rústica para casas de campo.

    def construir_estrutura(self):
        self.casa.add('Estrutura de madeira com ambientes aconchegantes')  # Material mais tradicional.

    def construir_telhado(self):
        self.casa.add('Telhado em duas águas')  # Telhado inclinado para escoamento da água da chuva.

    def pintar_casa(self):
        self.casa.add('Cores pastéis')  # Pintura suave para combinar com o ambiente campestre.

    def mobiliar_casa(self):
        self.casa.add('Móveis estilo vintage')  # Móveis rústicos que remetem a um estilo clássico.

    def get_casa(self):
        return self.casa  # Retorna a casa finalizada.

# A classe Casa representa o produto final da construção.
class Casa:
    def __init__(self):
        self.partes = []  # Lista que armazena todas as partes da casa.

    def add(self, parte):
        self.partes.append(parte)  # Adiciona uma nova parte ao objeto Casa.

    def descrever(self):
        return ', '.join(self.partes)  # Retorna uma string com todas as partes da casa construídas.

# O DiretorDeConstrucao atua como o Director no padrão Builder.
# Ele controla a ordem de construção, garantindo que os passos sejam seguidos corretamente.
class DiretorDeConstrucao:
    def __init__(self, construtor):
        self._construtor = construtor  # Recebe um builder concreto e o armazena.

    def construir_casa(self):
        self._construtor.construir_fundacao()
        self._construtor.construir_estrutura()
        self._construtor.construir_telhado()
        self._construtor.pintar_casa()
        self._construtor.mobiliar_casa()
        return self._construtor.get_casa()  # Retorna a casa construída.

# Testando a construção das casas com diferentes builders.
if __name__ == "__main__":
    construtor_moderno = ConstrutorCasaModerna()
    diretor = DiretorDeConstrucao(construtor_moderno)
    casa = diretor.construir_casa()
    print(casa.descrever())  # Exibe a casa moderna construída.

    construtor_campo = ConstrutorCasaDeCampo()
    diretor = DiretorDeConstrucao(construtor_campo)
    casa = diretor.construir_casa()
    print(casa.descrever())  # Exibe a casa de campo construída.