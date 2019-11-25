import math
t = int(input())

for _ in range(t):
    n = int(input())

    num_start = int('1'*n)
    num_end = int('9'* n)
    # print(num_start,num_end)

    ans = -1

    for i in range(num_start,num_end+1):
        x = i
        sum = 0
        flag=True
        while x>0:
            if x%10 ==0:
                flag=False
                break
            sum+= math.pow(x%10,2)
            x = x//10
        ans = round(math.sqrt(sum))
        print(math.sqrt(sum), ans  , sum ,  i)
        if ans == math.sqrt(sum) and flag:
            ans = i
            break
        else:

            continue
    print(ans)
