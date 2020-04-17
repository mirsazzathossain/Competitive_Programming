from sys import stdin

for tag in stdin:
    tag = tag[:len(tag)-1]

    tagnum = input()
    s = input()

    rslt =""
    flag = False
    word = ""
    for i in range(len(s)):
        if s[i] == '<':
            if flag == True:
                flag = False
                rslt += word
                rslt += s[i]
                word = ""
            else:
                flag = True
                rslt += s[i]
        elif s[i] == '>':
            if flag == True:
                flag = False
                nl = ""
                for k in range(len(tag)):
                    nl += " "

                backup = word
                nword = ""
                previdx = 0
                while True:
                    index = word.lower().find(tag.lower())

                    if index != -1:
                        word = word.lower().replace(tag.lower(), nl, 1)
                        if index != 0:           
                            nword += backup[previdx:index]
                        nword += tagnum
                        previdx = index + len(tag)
                    else:
                        nword += backup[previdx:]
                        break

                rslt += nword
                word = ""
                rslt += s[i]
            else:
                rslt += s[i]
        else:
            if flag == True:
                word += s[i]
            else:
                rslt += s[i]
    if word == "":
        print(rslt)
    else:
        print(rslt+word)