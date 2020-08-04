t = int(input())

for __ in range(t):
    
    s = input()
    ok = True
    iniit = 0
    res = 0
    while True:
        curr = iniit
        iniit+=1
        ok = True
        for i in s:
            res+=1
            if i=="+":
                curr+=1
            else:
                curr-=1
            if curr<0:
                ok = False

                break
        if ok:
            break
    print(res)
class Points(obj):
    def __init__(self,x,y,z):
        self.x = x
        self.y = y
        self.z  = z
    
    

