from sys import stdin

for line in stdin:
    line = line[:len(line)-1]

    line = [x.lower() for x in line.split()]

    cnt = 0
    prev = False
    for i in range(len(line)):
        if i != len(line)-1:
            if line[i][0] == line[i+1][0]:
                if prev == False:
                    cnt+=1
                    prev = True
            else:
                prev = False
    print(cnt)