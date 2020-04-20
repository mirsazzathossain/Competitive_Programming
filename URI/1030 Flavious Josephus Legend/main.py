import sys
sys.setrecursionlimit(10010)


def josephus(n, k):
    if n == 1:
        return 0
    return (josephus(n-1, k)+k)%n

t = int(input())
for i in range(t):
    n, k = [int(x) for x in input().split()]

    print("Case %d: %d" %(i+1,josephus(n, k)+1))

