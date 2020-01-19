#Write your code here

n,k,l=map(int,input().split(" "))

arr=list(map(int,input().split(" ")))

ans=100000000000000000000


for i in range(min(arr),max(arr)+1):
    inc=0
    dec=0
    for j in arr:
        if j<i:
            inc +=i-j
        elif j>i:
            dec+=j-i
    if inc>=dec:
        if dec*k + (inc-dec)*l<=ans:
            ans = dec*k + (inc-dec)*l
print(ans)


            
