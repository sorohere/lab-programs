import heapq

def prim(V, edges, start):
    adj = [[] for _ in range(V)]
    for u, v, wt in edges:
        adj[u].append((v, wt))
        adj[v].append((u, wt))  # For undirected graph
    
    min_heap = [(0, start)]  # (weight, vertex)
    visited = set()
    mst_cost = 0

    while min_heap:
        weight, u = heapq.heappop(min_heap)
        
        if u in visited:
            continue
            
        visited.add(u)
        mst_cost += weight
        
        for v, wt in adj[u]:
            if v not in visited:
                heapq.heappush(min_heap, (wt, v))
    
    return mst_cost

# Example usage
V = 5  # Number of vertices
edges = [
    (0, 1, 5),
    (1, 2, 20),
    (1, 3, 10),
    (3, 4, 5),
    (2, 4, 1)
]
start_vertex = 0  # Starting vertex for Prim's algorithm

mst_cost = prim(V, edges, start_vertex)
print("Minimum Cost of Spanning Tree:", mst_cost)
