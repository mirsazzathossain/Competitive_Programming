from sys import stdin

first = False

for line in stdin:
    year = int(line)
    
    if (first == True):
        print("")

    festival = False
    leap = False
    first = True

    if (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)):
        print("This is leap year.")
        festival = True
        leap = True

    if (year%15 == 0) :
        print("This is huluculu festival year.")
        festival = True

    if (year%55 == 0 and  leap == True):
        print("This is bulukulu festival year.")

    if festival == False:
        print("This is an ordinary year.")
    