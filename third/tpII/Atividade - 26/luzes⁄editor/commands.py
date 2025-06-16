class Comando:
    def executar(self):
        pass

    def desfazer(self):
        pass

class ComandoLigarLuz(Comando):
    def __init__(self, luz):
        self.luz = luz

    def executar(self):
        self.luz.ligar()

    def desfazer(self):
        self.luz.desligar()

class ComandoDesligarLuz(Comando):
    def __init__(self, luz):
        self.luz = luz

    def executar(self):
        self.luz.desligar()

    def desfazer(self):
        self.luz.ligar()

class ComandoAjustarIntensidade(Comando):
    def __init__(self, luz, novo_valor):
        self.luz = luz
        self.novo_valor = novo_valor
        self.anterior = luz.intensidade

    def executar(self):
        self.luz.ajustar_intensidade(self.novo_valor)

    def desfazer(self):
        self.luz.ajustar_intensidade(self.anterior)