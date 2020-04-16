n = int(input())

for i in range(n):
    s1, s2 = [x for x in input().split()]

    for i in range(min(len(s1), len(s2))):
        print(s1[i], end="")
        print(s2[i], end="")

    if len(s1) != len(s2):
        print(s2[len(s1):] if len(s1)<len(s2) else s1[len(s2):])
    else: print("")