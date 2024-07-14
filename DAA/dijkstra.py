# best: O((V+E)logV) worst: O(V²)

def dijkstra(V, edges, S):
    # Create adjacency list
    adj = [[] for i in range(V)]
    for u, v, wt in edges:
        adj[u].append((v, wt))
        adj[v].append((u, wt))  # For undirected graph

    dist = [float('inf')] * V
    dist[S] = 0
    unvisited = set(range(V))
    
    while unvisited:
        u = min(unvisited, key=lambda vertex: dist[vertex])  # if dist[u] == inf: break
        unvisited.remove(u)
        
        for v, weight in adj[u]:
            if v in unvisited:
                if dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
    
    return dist

v, e = list(map(int, input("enter the no. of vertex and edges: ").split()))
edges = []
for i in range(e):
    edge = list(map(int, input("enter edge (u, v, wt): ").split()))
    edges.append(edge)

source = 0
dist = dijkstra(v, edges, source)
    
print(dist)
