import copy

class Inimigo:
    def __init__(self, tipo, nivel, vida):
        self.tipo = tipo
        self.nivel = nivel
        self.vida = vida

    # O método clone() é um "construtor alternativo". Diferente do __init__, que cria um novo objeto, 
    # clone() copia um objeto já existente. A cópia pode ser shallow (mantém a mesma referência) 
    # ou deep (cria uma nova referência na memória).

    def clone(self):
        return copy.deepcopy(self)

    def __str__(self):
        return f"Tipo: {self.tipo} | Nível: {self.nivel} | Vida: {self.vida}"  

# Criando um protótipo de inimigo (Orc)
orc_prototipo = Inimigo("Orc", 5, 100)

# Clonando para criar novos tipos de inimigos
troll = orc_prototipo.clone()
troll.tipo = "Troll das Masmorras"
troll.nivel = 1
troll.vida = 300

goblin = orc_prototipo.clone()
goblin.tipo = "Goblin"
goblin.nivel = 2
goblin.vida = 80

# Exibindo informações para garantir que são independentes
print(orc_prototipo)
print(troll)
print(goblin)
