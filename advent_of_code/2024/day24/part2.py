import networkx as nx
import matplotlib.pyplot as plt

g = nx.Graph()

n = int(input())
for i in range(0,n):
    line = input()
    line = line.strip().split(" ")
    g.add_edge(line[0],line[3])
    print(line[0], "-->", line[3])
    print(line[0], "-->", line[3])
    g.add_edge(line[2],line[3])

nx.draw(g)
plt.show()
