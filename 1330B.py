t =int(input())
def fac(arr):
    for i in range(1,max(arr)+1):
        if i not in arr:
            return False
    return True
for _ in range(t):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    d = {}
    for i in arr:
        d[i] = d.get(i,0)+1

    temp1 = []
    temp2 = []
    for k,v in d.items():
        if v==2:
            temp1.append(k)
            temp2.append(k)
        else:
            temp2.append(k)
    n_1 = len(temp1)
    n_2 = len(temp2)
    temp1.sort()
    temp2.sort()
    count=0
    # print(temp2,sorted(arr[0:n_2]))
    # print(temp1,sorted(arr[n_2:]))
    # print(temp1,sorted(arr[0:n_1]))
    # print(temp2,sorted(arr[n_1:]))
    bol = None
    bul1 = True
    bul2 = True
    if n_1>0 and n_2>0:
         
        bul1 = fac(temp1)
        bul2 = fac(temp2)
    if temp2==sorted(arr[0:n_2]):
        if temp1==sorted(arr[n_2:]):
            count+=1
            bol = True
    if temp1==sorted(arr[0:n_1]):
        if temp2==sorted(arr[n_1:]):
            count+=1
            bol = False
    # print(bul1 , bul2)
    if bul1==False and bul2==False:
        count=0
    if count==2:
        print(count)
        print(f"{len(temp2)} {len(temp1)}")
        print(f"{len(temp1)} {len(temp2)}")
    elif count==1:
        print(count)
        if bol:
            print(f"{len(temp2)} {len(temp1)}")
        else:
            print(f"{len(temp1)} {len(temp2)}")

    else:
        print(count)


