t = int(input(""))

for _ in range(t):

    n = int(input(""))

    a = list(map(int,input().split(" ")))
    b = list(map(int,input().split(" ")))
    x = set()
    ans = "YES"
    for i in range(n):
        if a[i]!=b[i] and i==0:
            ans = "NO"
            break
        elif a[i]==b[i]:
            x.add(a[i])
        else:
            if a[i]>b[i]:
                if -1 not in x:
                    ans="NO"
                    break
                else:
                    x.add(a[i])
                

                 
            else :

                if 1 not in x:
                    ans = "NO"
                else:
                    x.add(a[i])
                
    print(ans)
