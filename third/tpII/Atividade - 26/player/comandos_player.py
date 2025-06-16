class Comando:
    def executar(self):
        pass

    def desfazer(self):
        pass

class PlayCommand(Comando):
    def __init__(self, player):
        self.player = player

    def executar(self):
        self.player.play()

    def desfazer(self):
        self.player.stop()

class PauseCommand(Comando):
    def __init__(self, player):
        self.player = player

    def executar(self):
        self.player.pause()

    def desfazer(self):
        self.player.play()

class StopCommand(Comando):
    def __init__(self, player):
        self.player = player

    def executar(self):
        self.player.stop()

    def desfazer(self):
        self.player.play()