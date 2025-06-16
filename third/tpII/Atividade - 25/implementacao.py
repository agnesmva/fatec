# Classe Produto representa um item da loja com id, nome e preço
class Produto:
    def __init__(self, id, nome, preco):
        self.id = id
        self.nome = nome
        self.preco = preco

    def __str__(self):
        return f'ID: {self.id} | Nome: {self.nome} | Preço: R$ {self.preco:.2f}'


# Iterador personalizado para percorrer a coleção de produtos
class IteradorProdutos:
    def __init__(self, produtos, reverso=False):
        self.produtos = produtos
        self.reverso = reverso
        self.posicao = len(produtos) - 1 if reverso else 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.reverso:
            if self.posicao < 0:
                raise StopIteration
            produto = self.produtos[self.posicao]
            self.posicao -= 1
            return produto
        else:
            if self.posicao >= len(self.produtos):
                raise StopIteration
            produto = self.produtos[self.posicao]
            self.posicao += 1
            return produto


# Coleção de produtos, que pode ser iterada com o iterador personalizado
class ColecaoProdutos:
    def __init__(self, reverso=False):
        self._produtos = []
        self.reverso = reverso

    def adicionar_produto(self, produto):
        """Adiciona um novo produto à coleção."""
        self._produtos.append(produto)

    def total_produtos(self):
        """Retorna a quantidade total de produtos na coleção."""
        return len(self._produtos)

    def __iter__(self):
        """Retorna o iterador para a coleção."""
        return IteradorProdutos(self._produtos, self.reverso)


# Exemplo de uso
if __name__ == "__main__":
    # Criando a coleção de produtos
    colecao = ColecaoProdutos()

    # Adicionando produtos
    colecao.adicionar_produto(Produto(1, 'Produto A', 29.99))
    colecao.adicionar_produto(Produto(2, 'Produto B', 49.99))
    colecao.adicionar_produto(Produto(3, 'Produto C', 19.99))

    print("Produtos na ordem normal:")
    for produto in colecao:
        print(produto)

    print("\nProdutos na ordem reversa:")
    colecao_reversa = ColecaoProdutos(reverso=True)
    colecao_reversa.adicionar_produto(Produto(1, 'Produto A', 29.99))
    colecao_reversa.adicionar_produto(Produto(2, 'Produto B', 49.99))
    colecao_reversa.adicionar_produto(Produto(3, 'Produto C', 19.99))

    for produto in colecao_reversa:
        print(produto)
