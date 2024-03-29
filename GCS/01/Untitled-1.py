#!/usr/bin/python3
import collections
def solve(n, input_names, input_prices):
  # Write your solution here. Use `print_fruit(name, min, max, average)`
  # to produce output.
  #
  # Warning: Printing unwanted or ill-formatted data to output will cause
  # the test cases to fail.
def print_fruit(name, min_price, max_price, average_price):
    print(name, min_price, max_price, average_price)
def main():
  case_count = int(input())
  for case_id in range(1, case_count + 1):
    n = int(input())
    names = []
    prices = []
    for _ in range(n):
      name, price = input().split()
      names.append(name)
      prices.append(int(price))
    print('Case #{}:'.format(case_id))
    solve(n, names, prices)
if __name__ == '__main__':
  main()