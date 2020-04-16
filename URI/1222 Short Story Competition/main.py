from sys import stdin

for line in stdin:
    n, l, c = [int(i) for i in line.split()]

    lst = [len(i) for i in input().split()]

    line = 0
    page = 0
    ch = 0
    for i in range(len(lst)):
        ch += lst[i]

        if ((ch < c) and (i != len(lst)-1)):
            ch += 1

        if ch == c:
            line += 1
            ch -= c
        
        if ch > c:
            line += 1
            ch = lst[i]
            if ((ch < c) and (i != len(lst)-1)):
                ch += 1
        
        if line == l:
            page += 1
            line -= l

    if line != 0 or ch != 0:
        print(page+1)
    else:
        print(page)
