def dfs(r,c,t,x,y,flag):
    
    if r==x and c==y and flag==False :
        flag = True
        return 1

    for i in [(-1,1),(1,-1),(-1,-1),(1,1)]:
        x1 = r+i[0]
        y1 = c+i[1]
        if 0<x1<=t and 0<y1<=t and flag==False:
            dfs(x1,y1,t,x,y,flag)
            
    

t = int(input())
a,b = map(int,input().split())
a1,b1 = map(int,input().split())
c1,c2 = map(int,input().split())

if b==c2 or a==c1:
    print("NO")
else:
    flag = False
    xx = dfs(a,b,t,c1,c2,flag)

    
    
    if flag==False:
        print("YES")
    else:
        print("NO")
         