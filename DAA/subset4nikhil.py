def subset_sum(arr, val):
    n = len(arr)
    dp = [[False] * (val + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = True
    
    for i in range(1, n + 1):
        for j in range(1, val + 1):
            if arr[i - 1] > j:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]]
    
    result = []

    def find_subsets(i, j, path):
        if i == 0 and j == 0:
            result.append(path)
            return
        if i == 0:
            return
        if dp[i - 1][j]:
            find_subsets(i - 1, j, path)
        if j >= arr[i - 1] and dp[i - 1][j - arr[i - 1]]:
            find_subsets(i - 1, j - arr[i - 1], path + [arr[i - 1]])
    
    find_subsets(n, val, [])
    return result

arr = [1, 2, 3, 7, 0, 0]
val = 10
result = subset_sum(arr, val)
for subset in result:
    print(subset)
