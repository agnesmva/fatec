# Interface Builder
class HamburgerBuilder:
    def add_bun(self): pass
    def add_patty(self): pass
    def add_cheese(self): pass
    def add_condiments(self): pass
    def get_result(self): pass

# Classe Produto
class Hamburger:
    def __init__(self):
        self.ingredients = []
    
    def add_ingredient(self, ingredient):
        self.ingredients.append(ingredient)
    
    def __str__(self):
        return f"Hambúrguer com: {', '.join(self.ingredients)}"

# Builders Concretos
class ClassicHamburgerBuilder(HamburgerBuilder):
    def __init__(self):
        self.hamburger = Hamburger()
    
    def add_bun(self):
        self.hamburger.add_ingredient("Pão de hambúrguer")
    
    def add_patty(self):
        self.hamburger.add_ingredient("Carne grelhada")
    
    def add_cheese(self):
        self.hamburger.add_ingredient("Queijo cheddar")
    
    def add_condiments(self):
        self.hamburger.add_ingredient("Alface, tomate, ketchup e maionese")
    
    def get_result(self):
        return self.hamburger

class CheeseburgerBuilder(HamburgerBuilder):
    def __init__(self):
        self.hamburger = Hamburger()
    
    def add_bun(self):
        self.hamburger.add_ingredient("Pão de hambúrguer")
    
    def add_patty(self):
        self.hamburger.add_ingredient("Carne grelhada")
    
    def add_cheese(self):
        self.hamburger.add_ingredient("Queijo cheddar duplo")
    
    def add_condiments(self):
        self.hamburger.add_ingredient("Picles, ketchup e mostarda")
    
    def get_result(self):
        return self.hamburger

# Classe Director
class Chef:
    def __init__(self, builder: HamburgerBuilder):
        self.builder = builder
    
    def make_hamburger(self):
        self.builder.add_bun()
        self.builder.add_patty()
        self.builder.add_cheese()
        self.builder.add_condiments()
        return self.builder.get_result()

# Interface de Usuário
if __name__ == "__main__":
    print("Escolha o tipo de hambúrguer:")
    print("1. Clássico")
    print("2. Cheeseburger")
    choice = input("Digite o número da opção desejada: ")
    
    if choice == "1":
        builder = ClassicHamburgerBuilder()
    elif choice == "2":
        builder = CheeseburgerBuilder()
    else:
        print("Opção inválida.")
        exit()
    
    chef = Chef(builder)
    hamburger = chef.make_hamburger()
    print(f"\nSeu pedido está pronto: {hamburger}")# Interface Builder
class HamburgerBuilder:
    def add_bun(self): pass
    def add_patty(self): pass
    def add_cheese(self): pass
    def add_condiments(self): pass
    def get_result(self): pass

# Classe Produto
class Hamburger:
    def __init__(self):
        self.ingredients = []
    
    def add_ingredient(self, ingredient):
        self.ingredients.append(ingredient)
    
    def __str__(self):
        return f"Hambúrguer com: {', '.join(self.ingredients)}"

# Builders Concretos
class ClassicHamburgerBuilder(HamburgerBuilder):
    def __init__(self):
        self.hamburger = Hamburger()
    
    def add_bun(self):
        self.hamburger.add_ingredient("Pão de hambúrguer")
    
    def add_patty(self):
        self.hamburger.add_ingredient("Carne grelhada")
    
    def add_cheese(self):
        self.hamburger.add_ingredient("Queijo cheddar")
    
    def add_condiments(self):
        self.hamburger.add_ingredient("Alface, tomate, ketchup e maionese")
    
    def get_result(self):
        return self.hamburger

class CheeseburgerBuilder(HamburgerBuilder):
    def __init__(self):
        self.hamburger = Hamburger()
    
    def add_bun(self):
        self.hamburger.add_ingredient("Pão de hambúrguer")
    
    def add_patty(self):
        self.hamburger.add_ingredient("Carne grelhada")
    
    def add_cheese(self):
        self.hamburger.add_ingredient("Queijo cheddar duplo")
    
    def add_condiments(self):
        self.hamburger.add_ingredient("Picles, ketchup e mostarda")
    
    def get_result(self):
        return self.hamburger

# Classe Director
class Chef:
    def __init__(self, builder: HamburgerBuilder):
        self.builder = builder
    
    def make_hamburger(self):
        self.builder.add_bun()
        self.builder.add_patty()
        self.builder.add_cheese()
        self.builder.add_condiments()
        return self.builder.get_result()

# Interface de Usuário
if __name__ == "__main__":
    print("Escolha o tipo de hambúrguer:")
    print("1. Clássico")
    print("2. Cheeseburger")
    choice = input("Digite o número da opção desejada: ")
    
    if choice == "1":
        builder = ClassicHamburgerBuilder()
    elif choice == "2":
        builder = CheeseburgerBuilder()
    else:
        print("Opção inválida.")
        exit()
    
    chef = Chef(builder)
    hamburger = chef.make_hamburger()
    print(f"\nSeu pedido está pronto: {hamburger}")