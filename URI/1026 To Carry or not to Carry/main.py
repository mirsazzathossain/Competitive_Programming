from sys import stdin

for line in stdin:
    a, b = [int(x) for x in line.split()]

    print(a^b)