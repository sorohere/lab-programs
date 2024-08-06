def dfs_recursive(graph, node, visited):
    if node not in visited:
        print(node)
        visited.append(node)  
        
        for neighbor in graph[node]:
            dfs_recursive(graph, neighbor, visited)


graph = {}

nodes = int(input("Enter the total number of nodes: "))
for i in range(nodes):
    key = int(input("Enter the key: "))
    value = list(map(int, input(f"Enter the nodes connected to {key}: ").split()))
    graph[key] = value
    
print("Graph:", graph)

visited = []
dfs_recursive(graph, 1, visited)
