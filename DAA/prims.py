def primsAlgo(graph, source):
    visited = []
    edges = []
    ans = []
    mstCost = 0

    visited.append(source)
    for vertex in graph[source]:
        edges.append((source, vertex[0], vertex[1]))

    while edges:
        u, v, w = findMin(edges)
        if v not in visited:
            visited.append(v)
            ans.append((u, v, w))
            mstCost += w

            for vertex in graph[v]:
                if vertex[0] not in visited:
                    edges.append((v, vertex[0], vertex[1]))

    return ans, mstCost

def findMin(edges):
    min_edge = edges[0]
    for edge in edges:
        if edge[2] < min_edge[2]:
            min_edge = edge

    edges.remove(min_edge)
    return min_edge

num = int(input("Enter the number of edges: "))
graph = {}
src = -1
srcvalue = float('inf')
for i in range(num):
    u, v, w = input("Enter the (source, destination, weight): ").split()
    if int(w) < srcvalue:
        src = int(u)
    if int(u) not in graph:
        graph[int(u)] = []
    if int(v) not in graph:
        graph[int(v)] = []
    
    graph[int(u)].append((int(v), int(w)))
    graph[int(v)].append((int(u), int(w)))

mst, mstCost = primsAlgo(graph, src)
print("MST: ", mst)
print("MST Cost: ", mstCost)
