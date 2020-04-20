t = int(input())

for i in range(t):
    s = [x for x in input().split()]

    rslt = ""

    for x in s:
        rslt += x[0]

    print(rslt)