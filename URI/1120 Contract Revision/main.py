while True:
    d, n = input().split()

    if(d == "0" and n == "0"): 
        break
    
    n = n.replace(d, "")
    rslt = int(n) if len(n) != 0 else 0

    print(rslt)


