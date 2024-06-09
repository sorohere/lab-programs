from collections import deque

def bfs_color(graph, source):
    colors = {}
    visited = set()
    queue = deque([(source, 0)])

    while queue:
        node, layer = queue.popleft()
        if node not in visited:
            visited.add(node)
            colors[node] = 'red' if layer % 2 == 1 else 'blue'
            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append((neighbor, layer + 1))
    
    return colors

# Example usage:
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'E'],
    'D': ['B', 'F'],
    'E': ['C', 'G'],
    'F': ['D'],
    'G': ['E']
}
source = 'A'

colors = bfs_color(graph, source)
for node, color in colors.items():
    print("Node:", node, "-> Color:", color)
