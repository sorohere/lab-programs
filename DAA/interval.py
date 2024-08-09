# def weighted_interval_scheduling(intervals):
#     intervals.sort(key=lambda x: x[1])

#     n = len(intervals)
#     dp = [0] * n

#     dp[0] = intervals[0][2] 
#     for i in range(1, n):
#         value_incl = intervals[i][2]
#         j = find_latest_non_overlapping(intervals, i)
#         if j != -1:
#             value_incl += dp[j]

#         value_excl = dp[i-1]

#         dp[i] = max(value_incl, value_excl)

#     return dp[n-1]

# def find_latest_non_overlapping(intervals, current_index):
#     for j in range(current_index - 1, -1, -1):
#         if intervals[j][1] <= intervals[current_index][0]:
#             return j
#     return -1


# n = int(input("Enter the number of intervals: "))
# intervals = []

# for i in range(n):
#     interval = list(map(int, input(f"enter (start, end, weight): ").split()))
#     intervals.append(interval)

# max_value = weighted_interval_scheduling(intervals)
# print(f"Maximum value subset of intervals: {max_value}")


def interval(edge, n):
    edge.sort(key = lambda x:x[1])
    
    dp = [0]*n
    dp[0] = edge[0][2]
    
    selected = [[] for i in range(n)]
    selected[0] = [edge[0]]
    
    
    for i in range(1, n):
        inc = edge[i][2]
        j = index(edge, i)
        if j != -1:
            inc += dp[j]
        exc = dp[i-1]
        
        
        if inc > exc:
            dp[i] = inc
            if j != -1:
                selected[i] = selected[j] + [edge[i]]
            else:
                selected[i] =[edge[i]]
        else:
            selected[i] = selected[i-1]
            dp[i] = exc
    
    return dp[n-1], selected[n-1]
    
def index(edge, i):
    for j in range(i-1, -1, -1):
        if edge[j][1] <= edge[i][0]:
            return j
            
    return -1
    
    
edge = [
    [1, 2, 100],
    [2, 5, 200],
    [3, 6, 300],
    [4, 8, 400],
    [5, 9, 500],
    [6, 10, 100]
]

# Get the maximum weight and the jobs contributing to it
ans, jobs = interval(edge, len(edge))
print("Maximum Weight:", ans)
print("Selected Jobs:", jobs)

# enter u, v, w: 1 2 100
# enter u, v, w: 2 5 200
# enter u, v, w: 3 6 300
# enter u, v, w: 4 8 400
# enter u, v, w: 5 9 500
# enter u, v, w: 6 10 100
