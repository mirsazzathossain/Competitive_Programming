n = int(input())

for i in range(n):
    s = input()

    l = s[0:int(len(s)/2)]
    r = s[int(len(s)/2) : len(s)]

    print(''.join(reversed(l)), end="")
    print(''.join(reversed(r)))