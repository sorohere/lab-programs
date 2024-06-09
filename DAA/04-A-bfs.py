def bfs(graph, source):
    visited = []
    queue = [source]

    while queue:
        current_node = queue.pop(0)
        if current_node not in visited:
            print(current_node, end=' ')
            visited.append(current_node)
            for neighbor in graph[current_node]:
                if neighbor not in visited and neighbor not in queue:
                    queue.append(neighbor)

graph = {
    '1': ['2', '3'],
    '2': ['1', '3', '4', '5'],
    '3': ['1', '2', '6', '7'],
    '4': ['2', '5', '8', '9'],
    '5': ['2', '4', '9'],
    '6': ['3', '7'],
    '7': ['3', '6'],
    '8': ['4', '9'],
    '9': ['4', '5', '8', '10'],
    '10': ['9']
}

source = '1'

print("\n")
print("source node", source, "using BFS:")
bfs(graph, source)
print("\n")
