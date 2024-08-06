def dfs(graph, source):
    visited = []
    
    def dfs_recursive(node):
        if node not in visited:
            print(node, end=' ')
            visited.append(node)
            for neighbor in graph.get(node, []):
                if neighbor not in visited:
                    dfs_recursive(neighbor)
    
    dfs_recursive(source)

# Example usage
graph = {}

nodes = int(input("Enter the total number of nodes: "))
for i in range(nodes):
    key = int(input("Enter the key: "))
    value = list(map(int, input(f"Enter the nodes connected to {key}: ").split()))
    graph[key] = value
    
print("Graph:", graph)

dfs(graph, 1)
