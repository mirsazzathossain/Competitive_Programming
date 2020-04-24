while True:
    b, n = [int(x) for x in input().split()]

    if b == 0 and n == 0:
        break

    reserve = [int(x) for x in input().split()]

    for i in range(n):
        debtor, creditor, debenture = [int(x) for x in input().split()]
        reserve[debtor-1] -= debenture
        reserve[creditor-1] += debenture

    flag = True
    for x in reserve:
        if x < 0:
            flag = False
    
    if flag == True:
        print("S")
    else:
        print("N")


