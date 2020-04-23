while True:
    n = int(input())

    if n == 0:
        break

    lst = [int(x) for x in input().split()]
    lst.append(lst[0])

    prev = ""
    first = ""
    cnt = 0

    for i in range(len(lst)):
        if i == 0:
            if lst[i] < lst[i+1]:
                prev = "u"
                first = "u"
                continue
            else:
                prev = "d"
                first = "d"
                continue
        if i != 1:
            if prev == "u":
                if lst[i] < lst[i-1]:
                    prev = "d"
                    cnt += 1
                else:
                    continue
            else:
                if lst[i] > lst[i-1]:
                    prev = "u"
                    cnt += 1
                else:
                    continue
    if first == prev:
        print(cnt)
    else:
        print(cnt+1)
        
            
        

