while True:
    n = int(input())
    if n == 0:
        break
    for i in range(n):
        lst = [int(x) for x in input().split()]

        cnt = 0;
        idx = 0;

        for j in range(len(lst)):
            if lst[j]<=127:
                cnt += 1
                idx = j
            if cnt > 1:
                break
        if cnt == 1:
            print(chr(ord('A')+idx))
        else:
            print("*")