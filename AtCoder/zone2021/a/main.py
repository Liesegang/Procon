s = input()

cnt = 0
for i in range(12 - 3):
  if s[i:i+4] == "ZONe":
    cnt += 1
print(cnt)