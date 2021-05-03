class Item:
  def __init__(self, name, price):
    self.name = name
    self.min = price
    self.max = price
    self.sum = price
    self.count = 1

  def update(self, price):
    self.min = min(self.min, price)
    self.max = max(self.max, price)
    self.sum += price
    self.count += 1

  def show(self):
    print(self.name, self.min, self.max, self.sum // self.count)

t = int(input())

for j in range(t):
  print(f"Case #{j+1}:")
  items = {}
  n = int(input())
  for i in range(n):
    name, price = input().split()
    price = int(price)
    if name in items.keys():
      items[name].update(price)
    else:
      items[name] = Item(name, price)


  for name in sorted(items.keys()):
    items[name].show()