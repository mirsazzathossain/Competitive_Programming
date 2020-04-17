from sys import stdin

for line in stdin:
    line = line[:len(line)-1]
    
    line = line.replace('o', '0')
    line = line.replace('O', '0')
    line = line.replace('l', '1')
    line = line.replace(',', '')
    line = line.replace(' ', '')


    rslt = ""
    flag = False
    for i in range(len(line)):
        if line[i]>='0' and line[i]<='9':
            rslt += line[i]
        else:
            print("error")
            flag = True
            break
    
    if flag == False:
        if rslt != "":
            rslt = int(rslt)
            if rslt <= 2147483647:
                print(rslt)
            else:
                print("error")
        else:
            print("error")