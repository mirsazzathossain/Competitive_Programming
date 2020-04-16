from sys import stdin

for line in stdin:
    t = int(line)
    
    expressions=[]
    answers=[]
    rslt=[]
    
    for i in range(t):
        expressions.append(input())

    for i in range(t):
        answers.append(input())

    cnt = 0
    for i in range(t):

        name, index, operator = answers[i].split()
        index = int(index) - 1

        x, y = expressions[index].split()
        y, z = y.split('=')

        x=int(x)
        y=int(y)
        z=int(z)

        if (operator == '+'):
            if (x+y) == z:
                cnt += 1
            else:
                rslt.append(name)
        elif (operator == '-'):
            if (x-y) == z:
                cnt += 1
            else:
                rslt.append(name)
        elif (operator == '*'):
            if (x*y) == z:
                cnt += 1
            else:
                rslt.append(name)
        else:
            if ((x+y) != z and (x-y) != z and (x*y) != z):
                cnt += 1
            else:
                rslt.append(name)
                
    if cnt == 0: 
        print("None Shall Pass!")
    elif cnt == t:
        print("You Shall All Pass!")
    else:
        rslt.sort()
        for i in range(len(rslt)):
            if(i == len(rslt)-1):
                print(rslt[i])
            else:
                print(rslt[i], end =" ")


    