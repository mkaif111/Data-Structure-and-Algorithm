# cook your dish here


t = int(input())
m = 1000000007

for _ in range(t):
    l , r = map(int,input().split(" "))
    if l&(l+1)==0:
        print(l)
    else:
        x = l&(l+1)
        if x<<1 <=r:
            x = x%m
            y = ((x<<1) - l-1)%(m)
            x = (x%m)*(y%(m)) + l
            print(x)
        else:
            x = x%m
            x= (x%m)*((l-r)%m) + l
            print(x)
