import numpy as np
import matplotlib.pyplot as plt

def s(i):
  return sum(map(lambda x: int(x),str(i)))

def sunuke(i):
  return i / s(i)

k = int(input())

cnt = 0
cry = 0
prev = 0
for i in range(1,k):
  t = int(str(cnt + 1) + '9' * cry)
  t = t/s(t)
  if(t <= prev):
    print("不正")
    print(i)
  print(t)
  prev = t
  cnt += 1
  if(cnt % 9 == 0):
    cnt = 0
    cry += 1

#plt.plot(x, y)
#plt.show()