from abc import ABC, abstractmethod

# Interface Componente
# Esta é a classe base abstrata para todos os componentes do quadro Kanban.
# Utilizamos a classe ABC (Abstract Base Class) para definir métodos que devem
# ser implementados por todas as subclasses.
class Componente(ABC):
    # Método abstrato mostrar_detalhes
    # Este método será implementado por todas as subclasses 
    # (projetos, listas e tarefas)
    # e será usado para exibir os detalhes do componente. 
    # O parâmetro `nivel` é usado para controlar a indentação 
    # ao mostrar a hierarquia dos componentes.
    @abstractmethod
    def mostrar_detalhes(self, nivel=0):
        pass

# Classe Tarefa (Cartão)
# Esta classe representa uma tarefa individual no quadro Kanban.
# Herda da classe Componente, o que significa que deve implementar 
# o método abstrato mostrar_detalhes.
class Tarefa(Componente):
    # Método construtor __init__
    # Inicializa uma nova instância de Tarefa com descrição, prioridade, 
    # duração e responsável.
    def __init__(self, descricao, prioridade, duracao, responsavel):
        self.descricao = descricao # Descrição da tarefa
        self.prioridade = prioridade # Prioridade da tarefa: Alta, Média, Baixa
        self.duracao = duracao  # Duração estimada da tarefa em horas
        self.responsavel = responsavel # Nome da pessoa responsável pela tarefa
    
    # Método mostrar_detalhes
    # Implementação do método abstrato da classe Componente.
    # Exibe os detalhes da tarefa, com a indentação apropriada para 
    # refletir sua posição na hierarquia.
    def mostrar_detalhes(self, nivel=0):
        # Prefixo de indentação baseado no nível
        prefixo = " " * (nivel * 2)
        # Exibição dos detalhes da tarefa
        print(f"{prefixo}Tarefa: {self.descricao}, Prioridade: {self.prioridade},Duração: {self.duracao}h, Responsável: {self.responsavel}")
# Classe Lista de Tarefas (Lista)
# Esta classe representa uma lista de tarefas no quadro Kanban.
# Herda da classe Componente, o que significa que deve implementar 
# o método abstrato mostrar_detalhes.
class ListaTarefas(Componente):
    # Método construtor __init__
    # Inicializa uma nova instância de ListaTarefas com um título e 
    # uma lista vazia de tarefas.
    def __init__(self, titulo):
        self.titulo = titulo # Título da lista de tarefas
        self.tarefas = [] # Lista para armazenar tarefas (instâncias de Tarefa)

    # Método adicionar
    # Adiciona uma nova tarefa à lista de tarefas.
    def adicionar(self, tarefa):
        self.tarefas.append(tarefa)  # Adiciona a tarefa à lista de tarefas

    # Método remover
    # Remove uma tarefa existente da lista de tarefas.
    def remover(self, tarefa):
        self.tarefas.remove(tarefa)  # Remove a tarefa da lista de tarefas

    # Método mostrar_detalhes
    # Implementação do método abstrato da classe Componente.
    # Exibe os detalhes da lista de tarefas, com a indentação apropriada 
    # para refletir sua posição na hierarquia.
    def mostrar_detalhes(self, nivel=0):
        # Prefixo de indentação baseado no nível
        prefixo = " " * (nivel * 2)
        # Exibição do título da lista de tarefas
        print(f"{prefixo}Lista: {self.titulo}")
        # Exibição dos detalhes de cada tarefa na lista
        for tarefa in self.tarefas:
            tarefa.mostrar_detalhes(nivel + 1)
# Classe Lista de Tarefas (Lista)
# Esta classe representa uma lista de tarefas no quadro Kanban.
# Herda da classe Componente, o que significa que deve implementar 
# o método abstrato mostrar_detalhes.
class ListaTarefas(Componente):
    # Método construtor __init__
    # Inicializa uma nova instância de ListaTarefas com um título e 
    # uma lista vazia de tarefas.
    def __init__(self, titulo):
        self.titulo = titulo # Título da lista de tarefas
        self.tarefas = [] # Lista para armazenar tarefas (instâncias de Tarefa)

    # Método adicionar
    # Adiciona uma nova tarefa à lista de tarefas.
    def adicionar(self, tarefa):
        self.tarefas.append(tarefa)  # Adiciona a tarefa à lista de tarefas

    # Método remover
    # Remove uma tarefa existente da lista de tarefas.
    def remover(self, tarefa):
        self.tarefas.remove(tarefa)  # Remove a tarefa da lista de tarefas

    # Método mostrar_detalhes
    # Implementação do método abstrato da classe Componente.
    # Exibe os detalhes da lista de tarefas, com a indentação apropriada 
    # para refletir sua posição na hierarquia.
    def mostrar_detalhes(self, nivel=0):
        # Prefixo de indentação baseado no nível
        prefixo = " " * (nivel * 2)
        # Exibição do título da lista de tarefas
        print(f"{prefixo}Lista: {self.titulo}")
        # Exibição dos detalhes de cada tarefa na lista
        for tarefa in self.tarefas:
            tarefa.mostrar_detalhes(nivel + 1)