while True:
    t = int(input())

    if t == 0:
        break

    n, m = [int(x) for x in input().split()]

    for i in range(t):
        x, y = [int(x) for x in input().split()]

        if n == x or m == y:
            print("divisa")
        elif n < x and m < y:
            print("NE")
        elif n > x and m > y:
            print("SO")
        elif n < x and m > y:
            print("SE")
        else:
            print("NO")