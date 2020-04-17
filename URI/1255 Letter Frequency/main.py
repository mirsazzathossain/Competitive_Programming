t = int(input())

for i in range(t):
    s = input()

    lst = []
    for i in range(26):
        lst.append(0)

    s = s.lower()
    for i in range(len(s)):
        if s[i]>='a' and s[i]<='z':
            lst[ord(s[i])-ord('a')]+=1
    mx = max(lst)
    rslt = ""

    for i in range(26):
        if lst[i] == mx:
            rslt += chr(i+ord('a'))

    rslt = ''.join(sorted(rslt))

    print(rslt)
        
