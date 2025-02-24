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
        



#Como os parametros passados variam de cada produto, diferente da atividade anterior, que tinha "Documento" e "Nome" como parametros. Nessa é necessário colocar uma lista com o que precisa ser criado

#também poderia passar o máximo de parametros e colocar eles como NULL nos produtos que não fazem uso, mas achei a lista mais prática


#instanciando os objs
factory = ProdutoFactory()


eletronico = ["Smartphone", 2000.0, "123456789"]
eletronico = factory.criarProduto("Eletronico", *eletronico)
eletronico.exibir_informacoes()


roupa = ["Camiseta", 50.0, 'M', "Azul"]
roupa = factory.criarProduto("Roupa", *roupa)
roupa.exibir_informacoes()


alimento = ["Arroz", 10.0, datetime(2025, 2, 24)]
alimento = factory.criarProduto("Alimento", *alimento)
alimento.exibir_informacoes()
