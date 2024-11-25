import networkx as nx
import matplotlib.pyplot as plt

# Criação do grafo
G = nx.DiGraph()

# Adiciona os nós
G.add_nodes_from(["A", "B", "C", "D", "E", "F", "G"])

# Adiciona as arestas com base na imagem
edges = [
    ("D", "A"), ("A", "B"), ("A", "C"), ("A", "F"), ("B", "E"), 
    ("C", "E"), ("F", "G"), ("E", "G"), ("F", "C")
]
G.add_edges_from(edges)

# Definindo o menor e o maior caminho
menor_caminho = [("D", "A"), ("A", "C")]
maior_caminho = [("D", "A"), ("A", "B"), ("B", "E"), ("E", "C")]

# Layout para o grafo
pos = {
    "A": (0, 1), "B": (-1, 0), "C": (1, 0), "D": (-1, 1.5), 
    "E": (2, 0), "F": (1, 1.5), "G": (3, 1)
}

plt.figure(figsize=(10, 6))

# Desenhar todas as arestas em cinza por padrão
nx.draw_networkx_edges(G, pos, edge_color='gray', arrows=True, arrowstyle='-|>', width=1)

# Desenhar o menor caminho em azul
nx.draw_networkx_edges(G, pos, edgelist=menor_caminho, edge_color='blue', width=2, arrows=True, arrowstyle='-|>')

# Desenhar o maior caminho em vermelho
nx.draw_networkx_edges(G, pos, edgelist=maior_caminho, edge_color='red', width=2, arrows=True, arrowstyle='-|>')

# Desenhar os nós e rótulos
nx.draw_networkx_nodes(G, pos, node_color='lightblue', node_size=700)
nx.draw_networkx_labels(G, pos, font_size=12, font_color='black')


# Exibir o gráfico
plt.title("Grafo com menor e maior caminho destacados entre D e C")
plt.axis("off")
plt.show()
