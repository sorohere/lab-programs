def bfs(graph, source):
    visited = []
    queue = [source]

    while queue:
        current_node = queue.pop(0)
        if current_node not in visited:
            print(current_node, end=' ')
            visited.append(current_node)
            
            # for neighbor in graph[current_node]:
            #     if neighbor not in visited and neighbor not in queue:
            #         queue.append(neighbor)
            
            queue.extend(list(set(graph[current_node]) - set(queue)))
                    
                    
graph = {}

nodes = int(input("enter the total number nodes : "))
for i in range(nodes):
    key = int(input("enter the key : "))
    value = list(map(int, input(f"Enter the nodes connected to {key}: ").split()))
    graph[key] = value
    
print(graph)

bfs(graph, 1)