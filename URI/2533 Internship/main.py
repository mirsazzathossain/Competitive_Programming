from sys import stdin

for line in stdin:
    t = int(line)

    mul = 0
    add = 0

    for i in range(t):
        n, c = [int(i) for i in input().split()]

        mul += n*c
        add += c

    rslt = mul/(add*100.0)
    print("%.4f" %rslt)