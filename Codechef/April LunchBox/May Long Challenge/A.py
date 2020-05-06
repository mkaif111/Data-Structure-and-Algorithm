t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split(" ")))

    b_case = 100000000
    w_case = 0
    v = []

    for i in range(n):
        count = 1
        for j in range(i,n-1):
            if abs(arr[j]-arr[j+1])<=2:


                count+=1
            else:
                break
      
        j=i
        while j>0:
            if abs(arr[j]-arr[j-1])<=2:

                count+=1
            else:
                break
            j-=1
        v.append(count)
v.sort()

print(v[0],v[-1])
        
