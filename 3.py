import itertools 
# def findsubsets(s, n): 
def findsubsets(s, n): 
    return [set(i) for i in itertools.combinations(s, n)] 

def mex(arr):
    arr.sort()
    if 1 not in arr:
        return 1
    for i in arr:
        if i+1 not in arr:
            return i+1
    return max(arr)+1


t = int(input())

for _ in range(t):
    n = int(input())
    s=0
    arr = list(map(int , input().split(" ")))
    for i in range(1,n):
        subset = findsubsets(arr,i)
        for sub in subset:
            sub = list(sub)
            s+=mex(sub)
    s+=mex(arr)
    print(s+1)