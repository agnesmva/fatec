class GerenciadoImpressoes:
    __instancia = None

    def __new__(cls):
        if GerenciadoImpressoes.__instancia is None:
            GerenciadoImpressoes.__instancia = super().__new__(cls)
        return GerenciadoImpressoes.__instancia
    
    def __init__(self):
        if not hasattr(self, 'fila'): #o método hasattr verifica se existe um atributo nesse, faço a negacao, caso não haja nenhuma lista, ele cria um nova
            self.fila = []
    

    def adicionarFila(self):
        doc = input("Digite o nome do documento que vai ser adicionado a fila: ")
        self.fila.append(doc)
        print(f"Documento {doc} adicionado a fila.\n\n")

    def removerFila(self):
        
        if self.fila:
            doc = self.fila.pop(-1) #remove o último documento inserido, caso deseje remover o primeiro trocar -1 por 0, o método recebe a posicao no array
            print(f"Documento {doc} removido da fila.")
        else:
            print("A fila está vazia!")
