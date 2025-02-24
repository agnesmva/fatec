from datetime import datetime

class Produto:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

    def exibir_informacoes(self):
        pass

    def adicionar_pedido(self):
        pass

class Eletronico(Produto):
    def __init__(self, nome, preco, numSerie):
        super().__init__(nome, preco)
        self.numSerie = numSerie

    def exibir_informacoes(self):
        print(f"Nome do Produto Eletrônico: {self.nome}, preço: {self.preco} e número de série: {self.numSerie}")

class Roupa(Produto):
    def __init__(self, nome, preco, tamanho, cor):
        super().__init__(nome, preco)
        self.set_tamanho(tamanho)
        self.cor = cor

    def set_tamanho(self, tamanho):
        tamanho_validos = ['P', 'M', 'G', 'GG']
        if tamanho in tamanho_validos:
            self.tamanho = tamanho
        else:
            raise ValueError("Tamanho não Identificado")

    def exibir_informacoes(self):
        print(f"Nome da Roupa: {self.nome}, preço: {self.preco}, cor: {self.cor} e tamanho {self.tamanho}")

class Alimento(Produto):
    def __init__(self, nome, preco, dataValidade):
        super().__init__(nome, preco)
        self.set_dataValidade(dataValidade)

    def set_dataValidade(self, dataValidade):
        if isinstance(dataValidade, datetime):
            self.dataValidade = dataValidade
        else:
            raise ValueError("A data de validade precisa ser uma instância de datetime.")

    def exibir_informacoes(self):
        print(f"Nome: {self.nome}, Preço: {self.preco}, Data de Validade: {self.dataValidade}")

class ProdutoFactory:
    def criarProduto(self, tipo, *args):
        if tipo == "Eletronico":
            return Eletronico(*args)
        elif tipo == "Roupa":
            return Roupa(*args)
        elif tipo == "Alimento":
            return Alimento(*args)
        else:
            raise ValueError("Tipo de produto desconhecido")

# Exemplo de uso:
factory = ProdutoFactory()

# Criando um eletrônico com vetor de parâmetros
vetor_eletronico = ["Smartphone", 2000.0, "123456789"]
eletronico = factory.criarProduto("Eletronico", *vetor_eletronico)
eletronico.exibir_informacoes()

# Criando uma roupa com vetor de parâmetros
vetor_roupa = ["Camiseta", 50.0, 'M', "Azul"]
roupa = factory.criarProduto("Roupa", *vetor_roupa)
roupa.exibir_informacoes()

# Criando um alimento com vetor de parâmetros
vetor_alimento = ["Arroz", 10.0, datetime(2025, 2, 24)]
alimento = factory.criarProduto("Alimento", *vetor_alimento)
alimento.exibir_informacoes()
