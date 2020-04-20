def joseph(lst, index, k, n):
    if len(lst) == 1:
        return lst[0]  
    
    lst.pop(index)

    index = ((index+k-1)%n)
    return joseph(lst, index, k, n-1)

while True:
    n = int(input())    

    if n == 0:
        break
    lst = ()
    for i in range(1, n+1):
        lst = lst + (i ,)

    for i in range(1, 300):
        if joseph(list(lst), 0, i, n-1) == 13:
            print(i)
            break

    



