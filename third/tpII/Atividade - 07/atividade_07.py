from abc import ABC, abstractmethod

class Veiculo(ABC):
    @abstractmethod
    def tipo(self):
        pass

class Motor(ABC):
    @abstractmethod
    def tipo(self):
        pass

class FabricaTransporte(ABC):
    @abstractmethod
    def criar_veiculo(self):
        pass
    
    @abstractmethod
    def criar_motor(self):
        pass

class FabricaTerrestre(FabricaTransporte):
    def criar_veiculo(self):
        return Carro()
    
    def criar_motor(self):
        return MotorTerra()
    
class FabricaAerea(FabricaTransporte):
    def criar_veiculo(self):
        return Aviao()
    
    def criar_motor(self):
        return MotorAr()

class FabricaAquatica(FabricaTransporte):
    def criar_veiculo(self):
        return Barco()
    
    def criar_motor(self):
        return MotorEletrico()

class Carro(Veiculo):
    def tipo(self):
        return "Carro"

class MotorTerra(Motor):
    def tipo(self):
        return "Combustão"
    
class Aviao(Veiculo):
    def tipo(self):
        return "Avião"

class MotorAr(Motor):
    def tipo(self):
        return "Aéreo"

class Barco(Veiculo):
    def tipo(self):
        return "Barco"

class MotorEletrico(Motor):
    def tipo(self):
        return "Elétrico"
    
class Cliente:
    def __init__(self, fabrica: FabricaTransporte):
        self.veiculo = fabrica.criar_veiculo()
        self.motor = fabrica.criar_motor()
    
    def descricao(self):
        return f"Tipo do carro:{self.veiculo.tipo()}\n Tipo do Motor:  {self.motor.tipo()}\n"

if __name__ == "__main__":
    escolha = input("Escolha o tipo de transporte: \n1 - terrestre\n2 - aereo \n3 - aquatico\n")
    
    if escolha == "1":
        fabrica = FabricaTerrestre()
    elif escolha == "2":
        fabrica = FabricaAerea()
    elif escolha == "3":
        fabrica = FabricaAquatica()
    else:
        print("Opção inválida!")
        exit()
    
    cliente = Cliente(fabrica)
    print(cliente.descricao())