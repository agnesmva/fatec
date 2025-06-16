class GerenciadorComandos:
    def __init__(self):
        self.executados = []
        self.refeitos = []

    def executar_comando(self, comando):
        comando.executar()
        self.executados.append(comando)
        self.refeitos.clear()

    def desfazer(self):
        if self.executados:
            cmd = self.executados.pop()
            cmd.desfazer()
            self.refeitos.append(cmd)

    def refazer(self):
        if self.refeitos:
            cmd = self.refeitos.pop()
            cmd.executar()
            self.executados.append(cmd)