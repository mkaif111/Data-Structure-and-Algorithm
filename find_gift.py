
t = int(input(" "))

for _ in range(t):

    n = int(input())
    s = input()

    x=0
    y=0
    prev = ""
    count=0
    f = ""
    for i in range(0,n,3):
        g = s[i:i+3]
        # print(g,f)
        
        if len(g)==3:

            if g[0]==g[1] and g[1]==g[2]:
                f+=g[0]
            else:
                f+=g
        else:
            f+=g
        
    # print(f)
    for i in f:
       
        if prev==i or (prev=="L" and i=="R") or (prev=="R" and i=="L") or (prev=="U" and i=="D") or (prev=="D" and i=="U"):
            prev = i
            continue
       
        if i=="L":
            x-=1
        elif i=="U":
            y+=1

        elif i=="R":
            x+=1

        elif i=="D":
            y-=1
        
        prev = i
       
    print(x,y)
        