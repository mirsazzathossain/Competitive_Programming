from sys import stdin

for line in stdin:
    line = line[:len(line)-1]

    rslt = []

    for i in range(27):
        rslt.append('.')

    for i in range(len(line)):
        if line[i] != ' ':
            rslt[ord(line[i])-ord('a')] = line[i]

    final = ""

    flag = False
    for i in range(27):
        if rslt[i] != '.':
            if flag == False:
                final += rslt[i]+':'
                flag = True
        else:
            if flag == True:
                final += rslt[i-1]+", "
                flag = False
    print(final[:len(final)-2])

