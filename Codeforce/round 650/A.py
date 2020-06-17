t = int(input())
for __ in range(t):
    a = input()
    ans = a[0:2]
    for i in range(2,len(a)):
        if i%2!=0:
            ans+=a[i]
    ans+=a[-1]
    print(ans)