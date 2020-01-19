t = int(input())

while t>0:
    s,w1,w2,w3=map(int,input().split(" "))
    arr = [w1,w2,w3]
    if sum(arr)<=s:
        print(1)
    else:
        rev_arr = arr[::-1]
        sm = 0
        count_1 = 1
        for i in range(len(rev_arr)):
            if sm+rev_arr[i]>s:
                sm=0
                sm+=arr[i]
                count_1+=1
            else:
                sm+=rev_arr[i]
        sm = 0
        count_2 = 1
        for i in range(len(arr)):
            if sm+arr[i]>=s:
                sm=0
                sm+=arr[i]
                count_2+=1
            else:
                sm+=arr[i]
        print(min(count_1,count_2))
