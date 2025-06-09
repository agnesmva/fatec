# Interface Observer
class Observer:
    def atualizar(self, publicacao):
        pass  # Método a ser implementado pelas subclasses

# Interface Subject
class Subject:
    def adicionar_seguidor(self, seguidor):
        pass

    def remover_seguidor(self, seguidor):
        pass

    def notificar_seguidores(self, publicacao):
        pass

# Classe Usuario que estende Subject
class Usuario(Subject):
    def __init__(self, nome):
        self.nome = nome
        self.seguidores = []

    def adicionar_seguidor(self, seguidor):
        self.seguidores.append(seguidor)

    def remover_seguidor(self, seguidor):
        if seguidor in self.seguidores:
            self.seguidores.remove(seguidor)

    def fazer_publicacao(self, texto):
        publicacao = f"{self.nome} publicou: {texto}"
        print(publicacao)
        self.notificar_seguidores(publicacao)

    def notificar_seguidores(self, publicacao):
        for seguidor in self.seguidores:
            seguidor.atualizar(publicacao)

# Classe Seguidor que implementa Observer
class Seguidor(Observer):
    def __init__(self, nome):
        self.nome = nome

    def atualizar(self, publicacao):
        print(f"Seguidor {self.nome} recebeu notificação: {publicacao}")

# Código de teste
if __name__ == "__main__":
    # Criando usuários
    ana = Usuario("Ana")
    joao = Usuario("João")

    # Criando seguidores
    maria = Seguidor("Maria")
    pedro = Seguidor("Pedro")
    lucas = Seguidor("Lucas")

    # Adicionando seguidores
    ana.adicionar_seguidor(maria)
    ana.adicionar_seguidor(pedro)

    joao.adicionar_seguidor(maria)
    joao.adicionar_seguidor(lucas)

    # Publicações
    ana.fazer_publicacao("Bom dia, mundo!")
    joao.fazer_publicacao("Hoje tem café no bule ☕")

    # Remover seguidor
    ana.remover_seguidor(pedro)
    ana.fazer_publicacao("Be BRAT")
