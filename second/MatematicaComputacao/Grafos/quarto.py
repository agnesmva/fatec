import networkx as nx
import matplotlib.pyplot as plt

# Criação do grafo
G = nx.MultiGraph()

# Adiciona os nós
G.add_nodes_from([1, 2, 3, 4, 5])

# Adiciona as arestas
edges = [
    (1, 2),  # a1
    (1, 2),  # a2, aresta repetida
    (2, 2),  # a3, laço
    (2, 3),  # a4
    (1, 3),  # a5
    (3, 4)   # a6
]
G.add_edges_from(edges)

# Layout para o grafo
pos = nx.spring_layout(G)  # Layout automático para uma visualização clara

# Desenha o grafo
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=700, font_size=12, font_color='black')


plt.title("Grafo com múltiplas arestas e laço")
plt.axis("off")
plt.show()
