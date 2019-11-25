t = int(input(''))
for _ in range(t):
    n,m=map(int,input().split(" "))
    arr = [ int(i) for i in input().split(" ")]
    dict = {}
    j = m
    for i in arr:
        if j<=0:
            j=m
        dict[i]=j
        print(i,j)
        j-=1
    print(dict)
    ans = []
    arr.sort()
    l = 0
    h = m
    answer = 1000000000000000000
    ##print(dict)
    while h<=n:
        ans = arr[l:h]
        diff = None
        if dict[max(ans)]!=dict[min(ans)]:
            diff = max(ans)-min(ans)
            if diff<=answer:
                answer = diff
        l = l + m
        h = h + m


    print(answer)
