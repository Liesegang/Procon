s = input()
s = s.strip("0")


def isPal(s):
  for i in range(len(s)):
    if s[i] != s[-i-1]:
      return False
  return True


if isPal(s):
  print("Yes")
else:
  print("No")
