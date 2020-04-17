from sys import stdin
import math

for line in stdin:
    if line.find('.') != -1:
        fao, fractional = [x for x in line[:len(line)-1].split('.')]
    else:
        fractional = '0'

    if fractional != "":
        fractional = float('.'+fractional)
    else:
        fractional = float('.0')

    line = float(line[:len(line)-1])

    cutoff = float(input())

    if fractional>cutoff:
        print(int(math.ceil(line)))
    else:
        print(int(math.floor(line)))
    
