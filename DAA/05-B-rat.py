Algo : 
DFS(node):
    if node is the cheese:
        return "Cheese found!"
    
    mark node as visited
    
    for each neighbor of node:
        if neighbor is not visited and not a wall:
            if DFS(neighbor) returns "Cheese found!":
                return "Cheese found!"
    
    return "Cheese not found."
