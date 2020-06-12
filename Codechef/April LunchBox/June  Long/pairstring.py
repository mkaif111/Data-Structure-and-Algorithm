t = int(input())

for __ in range(t):
    # n = int(input())
    s = input()
    count_xy = 0
    count_yx = 0
    for i in range(len(s)-1):
        if s[i]+s[i+1]=="xy":
            count_xy+=1
        elif s[i]+s[i+1]=="yx":
            count_yx+=1
    


    print(max(count_xy,count_yx))