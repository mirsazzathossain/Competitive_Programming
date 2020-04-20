import sys
import math
sys.setrecursionlimit(3505)

k = []

def sieve():
    prime = [True for i in range(32625)]

    for i in range(2, int(math.sqrt(32625+1)), 1):
        if (prime[i] == True):
            for j in range(i*i, 32625, i):
                prime[j] = False
    for i in range(2, 32625):
        if prime[i] == True:
            k.append(i)
sieve()

def josephus(n, index):
    if n == 1:
        return 0
    return (josephus(n-1, index+1)+k[index])%n

while True:
    n = int(input())
    if n == 0:
        break
    print(josephus(n, 0)+1)

