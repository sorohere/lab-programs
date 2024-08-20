def is_bipartite(graph, source):
    
    color = [-1] * len(graph)
    
    queue = [source]
    color[source] = 0
    
    while queue:
        current_node = queue.pop(0)
        
        for neighbor in graph[current_node]:
            if color[neighbor] == -1:
                color[neighbor] = 1 - color[current_node]
                queue.append(neighbor)
                
            elif color[neighbor] == color[current_node]:
                return False
    
    return True

# Example graph (represented as an adjacency list)
graph = {
    0: [1, 3],
    1: [0, 2],
    2: [1, 3, 4, 5],
    3: [0, 2],
    4: [2, 5],
    5: [2, 4],
}

# Check if the graph is bipartite
source_node = 0
if is_bipartite(graph, source_node):
    print("The graph is bipartite.")
else:
    print("The graph is not bipartite.")
