t = int(input())

for _ in range(t):

    n,a,b,c,d = map(int,input().split(" "))

    if n*(a-b)>c+d or n*(a+b)<c-d:
        print("No")
    else:
        print("Yes")

    
        
    