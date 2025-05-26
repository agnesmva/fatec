# Parte 1: Implementação com MVC

# MODEL
class CalculadoraModel:
    def __init__(self, numero1=0, numero2=0):
        self.numero1 = numero1
        self.numero2 = numero2

    def somar(self):
        return self.numero1 + self.numero2

    def subtrair(self):
        return self.numero1 - self.numero2

    def multiplicar(self):
        return self.numero1 * self.numero2

    def dividir(self):
        if self.numero2 == 0:
            return "Erro: Divisão por zero"
        return self.numero1 / self.numero2

# VIEW
class CalculadoraView:
    def obter_entrada(self):
        n1 = float(input("Digite o primeiro número: "))
        n2 = float(input("Digite o segundo número: "))
        operacao = input("Escolha a operação (+, -, *, /): ")
        return n1, n2, operacao

    def mostrar_resultado(self, resultado):
        print("Resultado:", resultado)

# CONTROLLER
class CalculadoraController:
    def __init__(self):
        self.model = CalculadoraModel()
        self.view = CalculadoraView()

    def executar(self):
        n1, n2, op = self.view.obter_entrada()
        self.model.numero1 = n1
        self.model.numero2 = n2

        if op == "+":
            resultado = self.model.somar()
        elif op == "-":
            resultado = self.model.subtrair()
        elif op == "*":
            resultado = self.model.multiplicar()
        elif op == "/":
            resultado = self.model.dividir()
        else:
            resultado = "Operação inválida"

        self.view.mostrar_resultado(resultado)

# Parte 2: Implementação com MVP

class CalculadoraViewMVP:
    def mostrar_menu(self):
        n1 = float(input("Digite o primeiro número: "))
        n2 = float(input("Digite o segundo número: "))
        op = input("Escolha a operação (+, -, *, /): ")
        return n1, n2, op

    def mostrar_resultado(self, resultado):
        print("Resultado:", resultado)

class CalculadoraPresenter:
    def __init__(self, view):
        self.view = view
        self.model = CalculadoraModel()

    def executar(self):
        n1, n2, op = self.view.mostrar_menu()
        self.model.numero1 = n1
        self.model.numero2 = n2

        if op == "+":
            resultado = self.model.somar()
        elif op == "-":
            resultado = self.model.subtrair()
        elif op == "*":
            resultado = self.model.multiplicar()
        elif op == "/":
            resultado = self.model.dividir()
        else:
            resultado = "Operação inválida"

        self.view.mostrar_resultado(resultado)

# Parte 3: Implementação com MVVM

class CalculadoraViewModel:
    def __init__(self):
        self.numero1 = 0
        self.numero2 = 0
        self.operacao = ""
        self.resultado = None
        self.model = CalculadoraModel()

    def calcular(self):
        self.model.numero1 = self.numero1
        self.model.numero2 = self.numero2

        if self.operacao == "+":
            self.resultado = self.model.somar()
        elif self.operacao == "-":
            self.resultado = self.model.subtrair()
        elif self.operacao == "*":
            self.resultado = self.model.multiplicar()
        elif self.operacao == "/":
            self.resultado = self.model.dividir()
        else:
            self.resultado = "Operação inválida"

class CalculadoraViewMVVM:
    def __init__(self, viewmodel):
        self.viewmodel = viewmodel

    def executar(self):
        self.viewmodel.numero1 = float(input("Digite o primeiro número: "))
        self.viewmodel.numero2 = float(input("Digite o segundo número: "))
        self.viewmodel.operacao = input("Escolha a operação (+, -, *, /): ")
        self.viewmodel.calcular()
        print("Resultado:", self.viewmodel.resultado)

# Execução
if __name__ == "__main__":
    print("Escolha a arquitetura:\n1 - MVC\n2 - MVP\n3 - MVVM")
    escolha = input("Opção: ")

    if escolha == "1":
        app = CalculadoraController()
        app.executar()
    elif escolha == "2":
        view = CalculadoraViewMVP()
        presenter = CalculadoraPresenter(view)
        presenter.executar()
    elif escolha == "3":
        vm = CalculadoraViewModel()
        view = CalculadoraViewMVVM(vm)
        view.executar()
    else:
        print("Opção inválida.")
