ans = []
delay = []
time = 0

list.sort(key = lambda x : x[1])

while list:
  x = list.pop(0)
  start = time
  end = start + x[0]

  ans.append(start, end)

  if end - x[1] > 0:
    delay.append(end - x[1])
  else:
    delay.append(0)


  
  time = end
