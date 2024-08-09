def prims(adj, start, ver):
    edges = []
    ans = []
    mincost = 0
    visited = []
    
    visited.append(start)
    for v, w in adj[start]:
        edges.append((start, v, w))
    
    while edges:
        u, v, w = getmin(edges)
        if v not in visited:
            visited.append(v)
            ans.append((u, v, w))
            mincost += w
            
            for i, j in adj[v]:
                    edges.append((v, i, j))
                    
    return mincost, ans
    
def getmin(edges):
    mini = edges[0]
    for i in edges:
        if mini[2] > i[2]:
            mini = i
    
    edges.remove(mini)        
    return mini

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
