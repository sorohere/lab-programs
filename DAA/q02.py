import time
import matplotlib.pyplot as plt
import numpy as np

sizes = [1000, 3000, 5000, 7000, 9000]
times = []

def linear_search(arr):
    for i in range(len(arr)-1):
        min = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]

for num in sizes:
    array = np.random.randint(0, num*2, size=num)

    time01 = time.time()
    linear_search(array)
    time02 = time.time()
    
    times.append(time02-time01)

plt.plot(sizes, times, c='r', label="Timing Graph")
plt.xlabel("Size of Array")
plt.ylabel("Time (s)")
plt.show()
