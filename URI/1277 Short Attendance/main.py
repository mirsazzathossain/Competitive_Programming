t = int(input())

for i in range(t):
    n = int(input())

    if n > 1:
        name = [x for x in input().split()]
        attendance = [x for x in input().split()]
    elif n == 1:
        name = []
        attendance = []
        name.append(input())
        attendance.append(input())

    first = True
    for j in range(n):
        s = attendance[j].replace('M', "")
        present = s.count('P')
        total = len(s)

        if present * 4 < total * 3:
            if first == False:
                print(" ", end="")
            print(name[j], end="")
            first = False
    
    print("")
