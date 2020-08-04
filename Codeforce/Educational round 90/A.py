t = int(input())

for __ in range(t):
    a,b,c = map(int , input().split(" "))
    if a<=c and b>1:
        print(1,b)
    else:
        if b==1 and c>=a or b/c >a:
            print(1,-1)
        
        else:
            print(-1,b)
    

