
first = True
while True:
    t = int(input())

    if t == 0:
        break

    if first == True:
        first = False
    else:
        print("")

    s = []
    mx = -1
    for i in range(t):
        s.append(input())
        if len(s[i]) > mx:
            mx = len(s[i])
    for i in range(t):
        for j in range(mx - len(s[i])):
            print(" ", end="")
        print(s[i])
    
