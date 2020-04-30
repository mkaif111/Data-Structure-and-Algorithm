t=int(input())

for _ in range(t):
    x , y = map(int,input().split(" "))
    a , b = map(int,input().split(" "))
    ans = 0
    if x==0 or y==0:
        ans = max(x,y)*a
    elif a==0 and b!=0:
        ans = 0
    elif a!=0 and b==0:
        ans = abs(x-y)*a
    else:
        option1 = (x+y)*a
        option2 = min(x,y)*b + abs(x-y)*a

        ans = min(option1 , option2)
    print(ans)
    