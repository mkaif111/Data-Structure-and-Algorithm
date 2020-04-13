t = int(input())

for _ in range(t):

    n , a , b = map(int ,input().split(" "))

    s = ""
    alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    i = 0
    if a!=1:

        for c in range(a):

            s+= alpha[i]

            if i<b-1:
                i+=1
    else:

        for i in range(n):
            s+=alpha[i]

    n = n-len(s)
    while n>0:
        if n>len(s):
            s +=s
            n = n-len(s)
        else:
            s +=s[0:n]
            n = 0
    print(s)
        


