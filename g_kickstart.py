t = int(input())

for j in range(1,t+1):
    n = int(input())
    arr = list(map(int,input().split(" ")))
    count = 0
    
    for i in range(1,n-1):
        if(arr[i]>arr[i+1] and arr[i]>arr[i-1]):
            count+=1
    if arr[0]>arr[1]:
        count+=1
    if arr[n-1]>arr[n-2]:
        count+=1
    
    print("Case #"+str(j)+":"+" "+str(count))