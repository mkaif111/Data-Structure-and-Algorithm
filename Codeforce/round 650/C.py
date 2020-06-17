t = int(input())

for __ in range(t):
    n,k = map(int,input().split(" "))
    s = input()
    count=0
    curr = 0
    prev = 0
    ans = 0
    l = []
    for i in range(len(s)):
        if s[i]=="1":
            l.append(i)
    # print(l)
    for i in range(len(l)-1):
        curr = l[i+1]-l[i]
        count = 0
        curr = curr- 2*(k+1)
        while curr>=0:
            count+=1
            curr-=2*(k+1)
        ans+=count
    if len(l)==0:
        ans+=1
        curr = n - 2*(k+1)
        while curr>=0:
            ans+=1
            curr -=2*(k+1)
        
    
        


        
    print("case" ,ans)
                


