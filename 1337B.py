t=int(input())

def void_a(x , n):

    if n==1:
        return x//2 + 10
    else:
        return void_a(x//2 + 10 , n-1)

for _ in range(t):

    x,n,m = map(int,input().split(" "))
    # print(x,n,m)

    if x-m*10<=0 or void_a(x,n)-m*10<=0:
        print("yes")
    else:
        print("no")

        

 
