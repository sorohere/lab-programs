def binary_search(arr, low, high, target):
    if high >= low:
        mid = (high + low) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            return binary_search(arr, low, mid - 1, target)
        else:
            return binary_search(arr, mid + 1, high, target)
    else:
        return -1

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

# Example usage:
arr = [2, 3, 4, 10, 40]
target = 10
