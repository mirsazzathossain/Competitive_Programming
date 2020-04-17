t = int(input())

for i in range(t):
    s = input()
    shift = int(input())

    rslt = ""
    for j in range(len(s)):
        if (ord(s[j]) - shift) < ord('A'):
            rslt += chr(ord('Z')-(ord('A') - (ord(s[j]) - shift)) + 1)
        else:
            rslt += chr(ord(s[j]) - shift)
    print(rslt)

