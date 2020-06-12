t = int(input())

def sol(arr,x):
    count_even = 0
    count_odd = 0
    for i in arr:
        if i%2==0:
            count_even+=1
        else:
            count_odd+=1
    # print(count_even,count_odd)
    if (count_even + count_odd>=x and count_odd%2!=0) or (x==1 and count_odd==1):
        return "Yes"
    else:
        return "No"
    


    

for __ in range(t):
    n, x = map(int,input().split(" "))
    arr = [int(i) for i in input().split(" ")]

    ans = sol(arr,x)
    print(ans)