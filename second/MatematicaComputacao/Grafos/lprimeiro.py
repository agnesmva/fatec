import networkx as nx
import matplotlib.pyplot as plt

# Cria o grafo
G = nx.Graph()

# Adiciona os nós (1 a 11)
G.add_nodes_from(range(1, 12))

# Adiciona as arestas fornecidas
arestas = [
    (0, 5), (0, 6), (2, 0), (2, 3), (3, 6), (3, 10),
    (4, 1), (5, 2), (5, 10), (6, 2), (7, 8), (7, 11),
    (8, 1), (8, 4), (10, 3), (11, 8)
]
G.add_edges_from(arestas)

# Configura o layout
pos = nx.spring_layout(G, seed=42)  # O seed garante uma disposição consistente
plt.figure(figsize=(10, 8))

# Desenha o grafo com estilo personalizado
nx.draw(
    G, pos, with_labels=True, 
    node_color='skyblue',         # Cor dos nós
    edge_color='gray',            # Cor das arestas
    node_size=700,                # Tamanho dos nós
    font_size=12,                 # Tamanho dos rótulos
    font_color='darkblue',        # Cor dos rótulos
    width=2,                      # Espessura das arestas
)

# Salva a imagem do grafo
plt.title("Atividade Agnes")
plt.savefig("grafo_personalizado.png", format="png", dpi=300)
plt.show()
