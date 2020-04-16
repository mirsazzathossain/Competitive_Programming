from sys import stdin

for line in stdin:
    italic = False
    bold = False
    for i in range(len(line)):
        if line[i] == '_':
            if italic == False:
                print("<i>", end="")
                italic = True
            else:
                print("</i>", end="")
                italic = False
        elif line[i] == '*':
            if bold == False:
                print("<b>", end="")
                bold = True
            else:
                print("</b>", end="")
                bold = False
        else:
            print(line[i], end="")