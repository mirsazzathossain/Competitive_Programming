from sys import stdin

for line in stdin:
    line = line[:len(line)-1]
    pro = int(input())

    cnt = 0
    rslt = 0
    for i in range(len(line)):
        if line[i] == 'R':
            cnt+=1
        else:
            if cnt != 0:
                mod = cnt%pro
                cnt -= mod
                rslt += int(cnt/pro)
                if mod != 0:
                    rslt += 1
                cnt = 0
            rslt += 1
    
    if cnt != 0:
        mod = cnt%pro
        cnt -= mod
        rslt += int(cnt/pro)
        if mod != 0:
            rslt += 1
    print(rslt)