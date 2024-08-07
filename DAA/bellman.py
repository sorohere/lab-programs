def bellman_ford(vertices, src, graph):
    V = len(vertices)
    dist = {vertex: float('inf') for vertex in vertices}
    dist[src] = 0

    for _ in range(V - 1):
        for u, v, w in graph:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    for u, v, w in graph:
        if dist[u] + w < dist[v]:
            print("Graph contains a negative-weight cycle")
            return None

    return dist

vertices = ['a', 'b', 'c', 'd', 'e', 't']

graph = [
    ('a', 'b', -4),
    ('a', 't', -3),
    ('b', 'd', -1),
    ('b', 'e', -2),
    ('c', 'b', 8),
    ('c', 't', 3),
    ('d', 'a', 6),
    ('d', 't', 4),
    ('e', 'c', -3),
    ('e', 't', 2)
]

print(bellman_ford(vertices, 'a', graph))
