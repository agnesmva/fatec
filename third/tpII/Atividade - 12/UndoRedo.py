import copy
from prettytable import PrettyTable
import csv 

class Texto:
    # Construtor: inicializa o conteúdo do texto, que começa vazio por padrão
    def __init__(self, conteudo=""):
        self.conteudo = conteudo

    # Método para adicionar texto ao conteúdo
    def adicionar(self, texto):
        self.conteudo += texto

    # Método para clonar o estado atual do objeto (utiliza deep copy para garantir independência)
    def clone(self):
        return copy.deepcopy(self)

    # Representação do objeto como string (retorna o conteúdo do texto)
    def __str__(self):
        return self.conteudo

# Classe de edição de conteúdo, que gerencia o histórico de edições
class Editor:
    # Construtor: inicializa o texto atual e duas listas para gerenciar o histórico e os textos removidos - troquei futuro por |"removido", pois faz mais sentido, não é o texto que está por vir, mas sim o texto removido que é armazenado na váriavel
    def __init__(self):
        self.estado_atual = Texto()  # Armazena o estado atual do texto
        self.historico = []  # Lista que mantém o histórico das edições
        self.removido = []  # Lista para armazenar o conteúdo removido, antes de ser desfeito

    # Método para escrever novo texto: adiciona o texto ao conteúdo e armazena o estado no histórico
    def escrever(self, texto):
        self.historico.append(self.estado_atual.clone())  # Armazena o estado anterior no histórico
        self.estado_atual.adicionar(texto)  # Adiciona o novo texto ao conteúdo

    # Método para desfazer a última edição: se o histórico não estiver vazio, restaura o último estado
    def desfazer(self):
        if self.historico:
            self.removido.append(self.estado_atual.clone())  # Armazena o estado atual no "removido"
            self.estado_atual = self.historico.pop()  # Restaura o último estado do histórico

    # Método para refazer a última edição desfeita: se houver algo no "removido", restaura esse estado
    def refazer(self):
        if self.removido:
            self.historico.append(self.estado_atual.clone())  # Armazena o estado atual no histórico
            self.estado_atual = self.removido.pop()  # Restaura o último estado removido

    # Representação do estado atual como string
    def __str__(self):
        return str(self.estado_atual)

# Teste da funcionalidade de edição e desfazer/refazer
editor = Editor()
# Lista para armazenar os dados para o CSV
table_data = [["Comando", "Conteúdo", "Histórico", "Removido"]]

# Teste de adicionar conteúdo
editor.escrever("Olá Bom dia ")
table_data.append([f'escrever("Olá Bom dia ")', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

editor.escrever("Tudo bem?")
table_data.append([f'escrever("Tudo bem?")', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

# Adicionando mais conteúdo
editor.escrever("Estou testando desfazer.")
table_data.append([f'escrever("Estou testando desfazer.")', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

# Testando desfazer
editor.desfazer()
table_data.append([f'desfazer()', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

editor.desfazer()
table_data.append([f'desfazer()', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

# Testando refazer
editor.refazer()
table_data.append([f'refazer()', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

editor.refazer()
table_data.append([f'refazer()', str(editor), str([str(item) for item in editor.historico]), str([str(item) for item in editor.removido])])

# Salvando os dados da tabela em um arquivo CSV
with open('historico_editor.csv', mode='w', newline='', encoding='utf-8') as file:
    writer = csv.writer(file)
    writer.writerows(table_data)

print("Tabela salva em 'historico_editor.csv'")