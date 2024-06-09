graph = {}

nodes = int(input("enter the total number nodes : "))
for i in range(nodes):
    key = int(input("enter the key : "))
    value = set((input(f"enter the nodes connected to {key} : ")).split())
    graph[f"{key}"] = value
    
print(graph)
