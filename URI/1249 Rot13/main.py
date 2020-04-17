from sys import stdin

for line in stdin:

    rslt = ""
    for i in range(len(line)):
        if((line[i] >= 'a' and line[i] <= 'z') or (line[i] >= 'A' and line[i] <= 'Z')):
            if line[i].islower() == True:
                if ord(line[i])+13 > ord('z'):
                    rslt += chr(((ord(line[i]) + 13) - ord('z')) + ord('a') - 1)
                else:
                    rslt += chr(ord(line[i])+13)
            else:
                if ord(line[i])+13 > ord('Z'):
                    rslt += chr(((ord(line[i]) + 13) - ord('Z')) + ord('A') - 1)
                else:
                    rslt += chr(ord(line[i]) + 13)
        else:
            rslt += line[i]
    print(rslt, end="")

