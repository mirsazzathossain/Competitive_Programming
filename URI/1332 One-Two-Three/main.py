t = int(input())

for i in range(t):
    s = input()

    if len(s) == 5:
        print(3)
    else:
        cnt = 0
        if s[0] == 'o':
            cnt+=1
        if s[1] == 'n':
            cnt+=1
        if s[2] == 'e':
            cnt+=1
        if cnt > 1:
            print(1)
        else:
            print(2)
        