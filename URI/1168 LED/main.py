n = int(input())

lst = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

for i in range(n):
    v = input()

    rslt = 0
    for j in range(len(v)):
        rslt += lst[int(v[j])]


    print(rslt, end=" ")
    print("leds")

