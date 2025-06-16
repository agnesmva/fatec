class EditorTexto:
    def __init__(self):
        self.conteudo = ""

    def escrever(self, texto):
        self.conteudo += texto

    def apagar(self, tamanho):
        self.conteudo = self.conteudo[:-tamanho]

    def __str__(self):
        return self.conteudo