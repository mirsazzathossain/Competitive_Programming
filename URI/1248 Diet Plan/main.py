t = int(input())

for i in range(t):
    d = input()
    breakfast = input()
    lunch = input()

    d = ''.join(sorted(d))
    rslt = ''.join(sorted(breakfast+lunch))

    diet = ""

    for x in range(len(d)):
        if diet.find(d[x]) == -1:
            diet += d[x]

    if len(diet) == len(rslt):
        flag = False
        for k in range(len(diet)):
            if diet[k] != rslt[k]:
                print("CHEATER")
                flag = True
                break
            else:
                continue
        if flag == False:
            print("")
    elif len(diet) < len(rslt):
        print("CHEATER")
    else:
        length = len(diet)
        nrslt = rslt
        ndiet = diet
        for j in range(length):
            Y = nrslt.find(diet[j])
            if Y != -1:
                nrslt = nrslt.replace(diet[j], "", 1)
                ndiet = ndiet.replace(diet[j], "", 1)
            else:
                continue
        if len(nrslt) != 0:
            print("CHEATER")
        else:
            print(ndiet)
