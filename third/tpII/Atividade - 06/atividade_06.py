# Aluna: Agnes Maria Varela
# Disciplina: Tec. de Programação II

#Atividade: Fazer um Sistemas de Pedido Online

from  datetime import datetime 

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
        self.set_tamanho = tamanho
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
        self.set_dataValidade = dataValidade

    def set_dataValidade(self, dataValidade):
        if isinstance(dataValidade) and datetime.stprtime(dataValidade): 
            self.dataValidade = dataValidade

        else:
            raise ValueError("A data de validade precisa ser uma instância de datetime.")
    
    def exibir_informacoes(self):
        print(f"Nome: {self.nome}, Preço: {self.preco}, Data de Validade: {self.dataValidade}")

class ProdutoFactory:
    def criarProduto(self, tipo, nome, preco, *args):
        if tipo == "Eletronico":
            return Eletronico(nome, preco, args[0])
        elif tipo == "Roupa":
            return Roupa(nome, preco, args[0], args[1])
        elif tipo == "Alimento":
            return Alimento(nome, preco, args[0])
        else:
            raise ValueError("Tipo de produto desconhecido")

# Exemplo de uso:
factory = ProdutoFactory()

# Criando um eletrônico
eletronico = factory.criarProduto("Eletronico", "Smartphone", 2000.0, "123456789")
eletronico.exibir_informacoes()

# Criando uma roupa
roupa = factory.criarProduto("Roupa", "Camiseta", 50.0, "M", "Azul")
roupa.exibir_informacoes()

# Criando um alimento
alimento = factory.criarProduto("Alimento", "Arroz", 10.0, datetime(2025, 2, 24))
alimento.exibir_informacoes()
