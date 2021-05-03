#!/usr/bin/python3

import collections

class UnionFind():
  def __init__(self, n):
    self.group = list(range(n))
    self.rank = [0] * n

  def unite(self, a, b):
    a = self.index(a)
    b = self.index(b)
    if(a == b) return

    if(self.rank[a] < self.rank[b]):
      self.group[a] = b
    else:
      self.group[b] = a
      if(self.rank[a] == self.rank[b]):
        self.rank[x] += 1

  def index(self, a):
    if(self.group[a] == a):
      return a
    else:
      self.group[a] = self.index(self.group[a])
      return self.group[a]

def solve(n, d, x, y):
  """Returns the sizes of groups in descending order."""
  uf = UnionFind(n)
  for i in range(d):
    uf.unite(x[i]-1, y[i]-1)

  arr = []
  for i in range(n):
    arr.append(uf.index(i))

  c = collections.Counter(arr)
  return sorted(c.values())[::-1]

def main():
  case_count = int(input())
  for case_id in range(1, case_count + 1):
    input()  # Skip empty line.
    n = int(input())
    d = int(input())
    x = []
    y = []
    for _ in range(d):
      xi, yi = input().split()
      x.append(int(xi))
      y.append(int(yi))
    s = solve(n, d, x, y)
    print('Case #{}: {}'.format(case_id, ' '.join(map(str, s))))
if __name__ == '__main__':
  main()