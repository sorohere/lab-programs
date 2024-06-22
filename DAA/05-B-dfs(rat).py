def dfs(graph, node, visited):
    if node not in visited:
        print(node) 
        visited.append(node)
        
        for neighbor in graph[node]:
            dfs(graph, neighbor, visited)
            
            
graph = {}

nodes = int(input("enter the total number nodes : "))
for i in range(nodes):
    key = int(input("enter the key : "))
    value = list(map(int, input(f"Enter the nodes connected to {key}: ").split()))
    graph[key] = value


print(graph)
visited = []
dfs(graph, 1, visited)



# Rat n cheese
# Algo : 
# DFS(node):
#     if node is the cheese:
#         return "Cheese found!"
    
#     mark node as visited
    
#     for each neighbor of node:
#         if neighbor is not visited and not a wall:
#             if DFS(neighbor) returns "Cheese found!":
#                 return "Cheese found!"
    
#     return "Cheese not found."
