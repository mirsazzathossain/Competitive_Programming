from sys import stdin

def isWord(s):
    for i in range(len(s)):
        if ((s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z')):
            continue
        elif (s[i] == '.' and i == len(s)-1 and len(s) != 1):
            continue
        else:
            return False

    return True

for line in stdin:
    s = [x for x in line.split()]

    length = 0
    cnt = 0
    for i in s:
        if isWord(i):
            cnt += 1
            if i[len(i)-1] == ".":
                length += len(i)-1
            else:
                length += len(i)

    if (cnt == 0 and len(line) != 0):
        print(250)
    elif int(length/cnt) <= 3:
        print(250)
    elif int(length/cnt) <= 5:
        print(500)
    else:
        print(1000)

