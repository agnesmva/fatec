class ControleRemoto:
    def __init__(self):
        self.historico = []

    def executar_comando(self, comando):
        comando.executar()
        self.historico.append(comando)

    def desfazer_comando(self):
        if self.historico:
            comando = self.historico.pop()
            comando.desfazer()