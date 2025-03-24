import copy

class Item:
    def __init__(self, nome, categoria, efeito, valor):
        self.nome = nome
        self.categoria = categoria
        self.efeito = efeito
        self.valor = valor

    def clone(self):
        return copy.deepcopy(self)
    
    def __str__(self):
        return f"Nome do item: {self.nome} | Categoria: {self.categoria} \n Efeito: {self.efeito} | Valor: {self.valor}\n"
    
 
itemTeste = Item("Cajado Mágico", "Cajado", "Rajadão Mágico", 54.89)

itemClonado = itemTeste.clone()

print(itemClonado)
print(f"Mostrar o item clonado alterado o nome")
itemClonado.nome = "Varinha das Fadas"
print(itemClonado)

"""
Aqui eu inseri outros exemplos para testar a lógica do clone, de acordo com o que foi pedido.
Criei um prototipo para cada tipo de item, pocao, arma e armadura, depois disso faço o clone de cada um dos itens e altero os atributos
"""
# Criando protótipos para cada categoria de item
# Protótipo para Poção
pocao_prototipo = Item("Poção de Cura", "Poção", "Restaura 50 pontos de vida", 25.0)

# Protótipo para Arma
arma_prototipo = Item("Espada Lendária", "Arma", "Aumenta ataque em 20 pontos", 120.0)

# Protótipo para Armadura
armadura_prototipo = Item("Armadura de Ferro", "Armadura", "Aumenta defesa em 15 pontos", 80.0)

# Clonando e personalizando os itens

# Criando um clone de Poção com modificações
pocao_clonada = pocao_prototipo.clone()
pocao_clonada.nome = "Poção de Mana"
pocao_clonada.efeito = "Restaura 30 pontos de mana"
pocao_clonada.valor = 30.0

# Criando um clone de Arma com modificações
arma_clonada = arma_prototipo.clone()
arma_clonada.nome = "Machado de Guerra"
arma_clonada.efeito = "Aumenta ataque em 40 pontos"
arma_clonada.valor = 150.0

# Criando um clone de Armadura com modificações
armadura_clonada = armadura_prototipo.clone()
armadura_clonada.nome = "Cota de Malha"
armadura_clonada.efeito = "Aumenta defesa em 25 pontos"
armadura_clonada.valor = 100.0

# Exibindo os itens originais e clonados
print("Protótipos Originais:")
print(pocao_prototipo)
print(arma_prototipo)
print(armadura_prototipo)

print("Itens Clonados e Personalizados:")
print(pocao_clonada)
print(arma_clonada)
print(armadura_clonada)

# Demonstração de independência entre o protótipo e os clones
print("\nAlterando um item clonado sem afetar o protótipo original:")
arma_clonada.nome = "Machado de Ferro"
arma_clonada.valor = 170.0

print("Protótipo Original de Arma (sem alterações):")
print(arma_prototipo)
print("Clone de Arma após modificações:")
print(arma_clonada)