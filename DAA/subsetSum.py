def subset_sum(weights, maxweight, num):
    M = [[0] * (maxweight + 1) for _ in range(num + 1)]

    for i in range(1, num + 1):
        for w in range(1, maxweight + 1):
            if weights[i] > w:
                M[i][w] = M[i - 1][w]
            else:
                M[i][w] = max(M[i - 1][w], weights[i] + M[i - 1][w - weights[i]])

    return M

def FindSolution(M, num, maxweight, weights):
  included = []
  while num:
    if weights[num] <= maxweight and weights[num] + M[num-1][maxweight-weights[num]] > M[num-1][maxweight]:
      included.append(weights[num])
      maxweight -= weights[num]
    num -= 1
  return included


num = int(input('Enter the number of items: '))
elements = [0] + list(map(int, input("enter items: ").split()))

msum = int(input('Enter the sum: '))

M = subset_sum(elements, msum, num)
print('Maximum value: ', M[num][msum])
print('Items included: ', FindSolution(M, num, msum, elements))
