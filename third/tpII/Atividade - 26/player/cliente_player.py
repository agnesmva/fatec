from player import Player
from comandos_player import PlayCommand, PauseCommand, StopCommand

class ControleMidia:
    def __init__(self):
        self.historico = []
        self.refeitos = []

    def executar_comando(self, cmd):
        cmd.executar()
        self.historico.append(cmd)
        self.refeitos.clear()

    def desfazer(self):
        if self.historico:
            cmd = self.historico.pop()
            cmd.desfazer()
            self.refeitos.append(cmd)

    def refazer(self):
        if self.refeitos:
            cmd = self.refeitos.pop()
            cmd.executar()
            self.historico.append(cmd)

player = Player()
controle = ControleMidia()

play = PlayCommand(player)
pause = PauseCommand(player)
stop = StopCommand(player)

controle.executar_comando(play)
controle.executar_comando(pause)
controle.desfazer()
controle.executar_comando(stop)
controle.refazer()