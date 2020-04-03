n = int(input())
if n>0:
    print(n)
elif abs(n)%10==0 and abs(n)<100:
    print(0)
else:
    x= str(n)
    a = int(x[-1])
    b = int(x[-2])

    
    # print(a,b)

    if abs(a)>=abs(b):
        print(x[:-1])
        

    else:
        c = str(abs(n))
        g = c[:len(c)-2]
        g = g+str(abs(a))
        print("-"+g)



