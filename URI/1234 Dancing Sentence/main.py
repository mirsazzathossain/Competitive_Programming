from sys import stdin

for line in stdin:

    previous = "first"
    for i in range(len(line)):
        if line[i] != ' ':
            if previous == "first":
                previous = "upper"
                print(line[i].upper(), end="")
            elif previous == "upper":
                previous = "lower"
                print(line[i].lower(), end="")
            else:
                previous = "upper"
                print(line[i].upper(), end="")
        else:
            print(line[i], end="")
