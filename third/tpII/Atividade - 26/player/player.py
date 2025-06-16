class Player:
    def __init__(self):
        self.estado = "Parado"

    def play(self):
        self.estado = "Tocando"
        print("▶️ Reproduzindo música")

    def pause(self):
        self.estado = "Pausado"
        print("⏸️ Música pausada")

    def stop(self):
        self.estado = "Parado"
        print("⏹️ Reprodução parada")