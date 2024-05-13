from collections import defaultdict, deque

def bfs(graph, source):
    visited = set()
    queue = [source]

    while queue:
        currentnode = queue.pop(0)
        if currentnode not in visited:
            print(currentnode, end=' ')
            visited.add(currentnode)
            queue.extend(graph[currentnode]-visited)

# graph = {
#     '1': {'2', '3'},
#     '2': {'1', '3', '4', '5'},
#     '3': {'1', '2', '6', '7'},
#     '4': {'2', '5', '8', '9'},
#     '5': {'2', '4', '9'},
#     '6': {'3', '7'},
#     '7': {'3', '6'},
#     '8': {'4', '9'},
#     '9': {'4', '5', '8', '10'},
#     '10': {'9'}
# }

graph = {}

nodes = int(input("enter the total number nodes : "))
for i in range(nodes):
    key = int(input("enter the key : "))
    value = set((input(f"enter the nodes connected to {key} : ")).split())
    graph[f"{key}"] = value

source = '1'

print("\n")
print("source node", source, "using BFS:")
bfs(graph, source)
print("\n")
