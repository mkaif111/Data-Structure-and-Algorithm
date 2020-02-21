t =int(input())

for _ in range(t):
    fAns = 0
    n = int(input())
    data = {'12':{'A':0,'B':0,'C':0,'D':0},'3':{'A':0,'B':0,'C':0,'D':0},'6':{'A':0,'B':0,'C':0,'D':0},'9':{'A':0,'B':0,'C':0,'D':0}}
    for __ in range(n):
        inp= input().split(" ")
        alpha = inp[0]
        time = inp[1]

        data[time][alpha] = data[time][alpha]+1

    # print(data)
    table = {}
    for i in ['12','3','9','6']:

        x = max(data[i]['A'],data[i]['C'],data[i]['B'],data[i]['D'])
        table[i]=x

    table_list = sorted(table.items(),key = lambda x:(x[1],x[0]) , reverse = True)
    ans = 0

    # for i in table_list[0]:
    arr = ['12' , '3' ,'9','6']
    mul = 100
    # print(table_list)
    count = 0
    while count<4:
        time , m = table_list[0]
        maxx = 0
        # print(time)
        for i in ['A','B','C','D']:
            if data[time][i]>=maxx:
                maxx = data[time][i]

                alpha = i
        for j in arr:
            data[j][alpha] = 0
        del data[time]
        # print(data)


        arr.remove(time)

        # print(arr)
        del table[time]
        for i in arr:

            x = max(data[i]['A'],data[i]['C'],data[i]['B'],data[i]['D'])
            table[i]=x
            # print(table[i])

        table_list = sorted(table.items(),key = lambda x:(x[1],x[0]) , reverse = True)

        # print(table_list)

        if maxx==0:
            ans -=100

        else:
            ans +=maxx*mul
        mul-=25
        # print(ans , maxx , alpha)
        count+=1
    fAns+=ans
print(fAns)
