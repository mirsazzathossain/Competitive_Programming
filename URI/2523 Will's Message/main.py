from sys import stdin

for line in stdin:
    n = int(input())
    x = [int(j) for j in input().split()]

    s = ""
    for j in range(n):
        s += line[x[j]-1]

    print(s)