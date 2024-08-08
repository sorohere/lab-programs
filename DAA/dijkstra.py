# best: O((V+E)logV) worst: O(V²)

def dijkstra(V, edges, S):
    adj = {i:[] for i in V}
    
    for u, v, wt in edges:
        adj[u].append((v, wt))
        adj[v].append((u, wt))  # For undirected graph
        

    dist = {x : float('inf') for x in vertex}
    dist[S] = 0
    unvisited = [i for i in V]
    
    while unvisited:
        u = min(unvisited, key=lambda vertex: dist[vertex])  # if dist[u] == inf: break
        unvisited.remove(u)
        
        for v, weight in adj[u]:
            if v in unvisited:
                if dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
    
    return dist

v, e = list(map(int, input("enter the no. of vertex and edges: ").split()))
graph = []
vertex = []

for i in range(e):
    temp = input("enter (u, v, w): ").split()
    if temp[0] not in vertex:
        vertex.append(temp[0])
    if temp[1] not in vertex:
        vertex.append(temp[1])
        
    temp[2] = int(temp[2])
    graph.append(temp)

source = '1'
dist = dijkstra(vertex, graph, source)
    
print(dist)
