t = int(input())

for __ in range(t):
    n,k = map(int,input().split(" "))
    ans = 0
    arr = list(map(int,input().split(" ")))
    for i in arr:
        ans+=max(0,i-k)
    print(ans)
    