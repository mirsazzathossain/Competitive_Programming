t = int(input())

for i in range(t):
    a, b = [x for x in input().split()]

    if len(a)<len(b):
        print("nao encaixa")
    else:
        if a[len(a)-len(b):] == b:
            print("encaixa")
        else:
            print("nao encaixa")