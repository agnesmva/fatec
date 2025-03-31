from abc import ABC, abstractmethod

# Interface para a construção de casas
class ConstrutorCasa(ABC):
    @abstractmethod
    def construir_fundacao(self):
        pass

    @abstractmethod
    def construir_estrutura(self):
        pass

    @abstractmethod
    def construir_telhado(self):
        pass

    @abstractmethod
    def pintar_casa(self):
        pass

    @abstractmethod
    def mobiliar_casa(self):
        pass

    @abstractmethod
    def get_casa(self):
        pass

# Implementação de uma casa moderna
class ConstrutorCasaModerna(ConstrutorCasa):
    def __init__(self):
        self.casa = Casa()

    def construir_fundacao(self):
        self.casa.add('Fundação moderna')

    def construir_estrutura(self):
        self.casa.add('Estrutura moderna com janelas amplas')

    def construir_telhado(self):
        self.casa.add('Telhado plano')

    def pintar_casa(self):
        self.casa.add('Pintura branca')

    def mobiliar_casa(self):
        self.casa.add('Móveis minimalistas')

    def get_casa(self):
        return self.casa

# Implementação de uma casa de campo
class ConstrutorCasaDeCampo(ConstrutorCasa):
    def __init__(self):
        self.casa = Casa()

    def construir_fundacao(self):
        self.casa.add('Fundação de pedra')

    def construir_estrutura(self):
        self.casa.add('Estrutura de madeira com ambientes aconchegantes')

    def construir_telhado(self):
        self.casa.add('Telhado em duas águas')

    def pintar_casa(self):
        self.casa.add('Cores pastéis')

    def mobiliar_casa(self):
        self.casa.add('Móveis estilo vintage')

    def get_casa(self):
        return self.casa

# Novo construtor para casa de luxo
class ConstrutorCasaLuxo(ConstrutorCasa):
    def __init__(self):
        self.casa = Casa()

    def construir_fundacao(self):
        self.casa.add('Fundação reforçada com concreto especial')

    def construir_estrutura(self):
        self.casa.add('Estrutura moderna com pé direito alto e vidros panorâmicos')

    def construir_telhado(self):
        self.casa.add('Telhado ecológico com isolamento térmico')

    def pintar_casa(self):
        self.casa.add('Pintura premium com acabamento sofisticado')

    def mobiliar_casa(self):
        self.casa.add('Móveis de alto padrão e design exclusivo')
        self.casa.add('Piscina aquecida e jardim planejado')

    def get_casa(self):
        return self.casa

# Classe que representa a casa construída
class Casa:
    def __init__(self):
        self.partes = []

    def add(self, parte):
        self.partes.append(parte)

    def descrever(self):
        return ', '.join(self.partes)

# Diretor responsável pelo processo de construção
class DiretorDeConstrucao:
    def __init__(self, construtor):
        self._construtor = construtor

    def construir_casa_padrao(self):
        self._construtor.construir_fundacao()
        self._construtor.construir_estrutura()
        self._construtor.construir_telhado()
        return self._construtor.get_casa()
    
    def construir_casa_completa(self):
        self._construtor.construir_fundacao()
        self._construtor.construir_estrutura()
        self._construtor.construir_telhado()
        self._construtor.pintar_casa()
        self._construtor.mobiliar_casa()
        return self._construtor.get_casa()

if __name__ == "__main__":
    # Construção de uma casa moderna completa
    construtor_moderno = ConstrutorCasaModerna()
    diretor = DiretorDeConstrucao(construtor_moderno)
    casa = diretor.construir_casa_completa()
    print("Casa Moderna:", casa.descrever())

    # Construção de uma casa de campo padrão
    construtor_campo = ConstrutorCasaDeCampo()
    diretor = DiretorDeConstrucao(construtor_campo)
    casa = diretor.construir_casa_padrao()
    print("Casa de Campo:", casa.descrever())

    # Construção de uma casa de luxo completa
    construtor_luxo = ConstrutorCasaLuxo()
    diretor = DiretorDeConstrucao(construtor_luxo)
    casa = diretor.construir_casa_completa()
    print("Casa de Luxo:", casa.descrever())