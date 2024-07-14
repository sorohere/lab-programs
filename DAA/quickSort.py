# best: O(nlogn) worst: O(n²)

def quickSort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        
        return quickSort(left) + middle + quickSort(right)

arr = [64, 25, 12, 22, 11]
ans = quickSort(arr)
print("Sorted array is:", ans)
