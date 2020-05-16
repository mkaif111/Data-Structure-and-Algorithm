
t = int(input())
for ___ in range(t):
    n = int(input())

    ans = []
    i = 10
    while(i<=n):
        if(n%i!=0):
            ans.append(n%i)
        n = n- n%i
        i = i*10
    ans.append(n)
    print(len(ans))
    for i in ans:
        print(i,end=" ")
    print()
    print(1000000000%9)