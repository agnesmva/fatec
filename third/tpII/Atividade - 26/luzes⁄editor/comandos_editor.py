class Comando:
    def executar(self):
        pass

    def desfazer(self):
        pass

class EscreverTexto(Comando):
    def __init__(self, editor, texto):
        self.editor = editor
        self.texto = texto

    def executar(self):
        self.editor.escrever(self.texto)

    def desfazer(self):
        self.editor.apagar(len(self.texto))