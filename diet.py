t=int(input())

for _ in range(t):
    n , m =map(int,input().split(" "))
    arr = [int(i) for i in input().split(" ")]
    store = 0
    day = None
    flag = False
    for i in range(n):
        if arr[i]+store>=m:

            store = arr[i]+store-m
        else:
            flag=True
            day = i+1
            break
    if flag:
        print("NO",end=" ")
        print(day)
    else:
        print("YES")
