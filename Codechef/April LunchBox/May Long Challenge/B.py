t = int(input())

for _ in range(t):
    n , q = map(int,input().split(" "))
    s = input("")
    virus = {}

    for i in s:
        virus[i] = virus.get(i,0)+1
    count=0
    patient =[]
    for key,val in virus.items():
        if val>1:
            # print(key,val,end=" ")
            patient.append(val)
            count+=1
    # print()

    for __ in range(q):
        c = int(input())
        ans=0
        for i in range(len(patient)):
            
            ans = ans+max(patient[i]-c,0)
            patient[i] = max(0,patient[i]-c)
            # print(patient[i])
        
        
        

        print(max(0,ans))

    