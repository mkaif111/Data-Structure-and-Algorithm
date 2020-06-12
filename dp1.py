t = int(input())

def powerex(n,m):
    res = 1
    a = 2
    while n>0:
        if(n & 1==1):
            res = (res*a)%m
        a = (a*a)%m
        n = n>>1
    return res

for __ in range(t):
    n = int(input())
    m = 1000000007
    print(powerex(n,m)-1)