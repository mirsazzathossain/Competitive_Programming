while True:
    h1, m1, h2, m2 = [int(x) for x in input().split()]

    if h1 == 0 and h2 == 0 and m1 == 0 and m2 == 0:
        break
    
    t1 = (h1*60)+m1
    t2 = (h2*60)+m2
    if t1>t2:
        print(1440-t1+t2)
    else:
        print(t2-t1)