from sys import stdin

for line in stdin:
    n, m = [int(i) for i in line.split()]

    cell = [0, 0, 0, 0]

    for i in range(n):
        c = [int(i) for i in input().split()]
        
        for j in range(len(c)):
            if c[j]==2:
                cell[0] = i
                cell[1] = j
            if c[j]==1:
                cell[2] = i
                cell[3] = j

    print(abs(cell[0]-cell[2]) + abs(cell[1]-cell[3]))
    