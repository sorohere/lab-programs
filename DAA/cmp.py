import time
import matplotlib.pyplot as plt
import random 

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def timed_sort(sort_func, arr):
    start_time = time.time()
    sort_func(arr)
    end_time = time.time()
    return end_time - start_time

# arr = [random.randint(1000, 2000) for i in range(3000)]
arr = [i for i in range(5000, -1, -1)]

arr_copy = arr.copy()
selectionTime = timed_sort(selection_sort, arr_copy)
print("Selection Sort time:", selectionTime)

arr_copy = arr.copy()
insertTime = timed_sort(insertion_sort, arr_copy)
print("Insertion Sort time:", insertTime)

arr_copy = arr.copy()
mergeTime = timed_sort(merge_sort, arr_copy)
print("Merge Sort time:", mergeTime)

sorting = ["Selection", "Insertion", "Merge"]
timing = [selectionTime, insertTime, mergeTime]

plt.bar(sorting, timing, color=["blue", "green", "red"])
plt.xlabel("Algo.")
plt.ylabel("Time(s)")
plt.show()
