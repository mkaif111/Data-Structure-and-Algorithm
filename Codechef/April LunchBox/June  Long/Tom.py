t = int(input())

for __ in range(t):
    tom = int(input())
    jerry = 0
    if tom%2!=0:
        print(tom//2)
    else:
        count = 0
        n = tom
        while n%2==0:
            count+=1
            n = n//2
        for i in range(2,tom,2):
            count_i = 0
            x = i
            while x%2==0:
                count_i+=1
                x = x//2
            if count_i>count:
                jerry+=1
        print(jerry)
