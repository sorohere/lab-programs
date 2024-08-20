ans = []
delay = []
time = 0

list

while list:
  x = list.pop(0)
  start = t
  end = start + x[0]

  if end - x[1] > 0:
    delay.append(end - x[1])
  else:
    delay.append(0)

  ans.append(start, end)
  
  time = end
