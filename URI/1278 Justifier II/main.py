start = True
while True:
    line = int(input())

    if line == 0:
        break

    if start == False:
        print("")
    else:
        start = False

    arr = []
    mx = -1
    for i in range(line):
        s = [x for x in input().split()]
        
        temp = ""
        first = True
        for j in range(len(s)):
            
            if first == False:
                temp += ' '
            temp += s[j]
            first = False
        arr.append(temp)

        if len(temp) > mx:
            mx = len(temp)

    for i in range(len(arr)):
        for j in range(mx - len(arr[i])):
            print(" ", end="")
        print(arr[i])

