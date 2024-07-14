def show(index, arr, ans, n, val):
    if sum(ans) == val:
        print(ans)
        
    if index >= n:
        return
        
    ans.append(arr[index])
    show(index + 1, arr, ans, n, val)
    ans.pop()
    show(index + 1, arr, ans, n, val)

string = [1, 2, 3 , 7, 0 , 0]
ans = []
n = len(string)
show(0, string, ans, n, 10)
