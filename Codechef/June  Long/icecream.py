t = int(input())

for __ in range(t):
    n = int(input())
    arr = list(map(int,input().split(" ")))

    change = 0
    ans = "YES"
    for i in arr:
        req_change = i-5
        if req_change==0:
            change+=i//5
        else:
            if req_change> change*5:
                ans = "NO"
                break
            else:
                change-=req_change//5
    print(ans)
        
