class Recipe:
    def __init__(self,ID,name,major,rtype,calorie):
        self.ID = ID
        self.name = name
        self.major = major
        self.rtype = rtype
        self.calorie = calorie
    

class MyRecipe:
    def __init__(self,rlist,klist):
        self.rlist = rlist
        self.klist = klist
    def getRCount(self,recipe):
        count = 0
        for R in self.rlist:
            if R.rtype.upper() == recipe.upper():
                cnt = 0
                for major in R.major:
                    if major  in self.klist:
                        cnt +=1
                    else:
                        break
                if cnt == len(R.major):
                    count+=1
        if count>0:
            return count
        else:
            return None
    def minCalorie(self):
        arr = []
        for r in self.rlist:
            arr.append([r.calorie,r])
        sorted(arr,key = lambda x: x[0])
        if len(arr)>=2:
            arr = [arr[0][1],arr[1][1]]
            return arr
        return []


t = int(input())
major = [ ]
rlist = []
klist = []
for T in range(t):
    ID = int(input())
    name = input()
    rtype = input()
    
    for temp in range(3):
        m = input()
        major.append(m)
    calorie = float(input())
    r = Recipe(ID,name,major,rtype,calorie)
    rlist.append(r)
m = int(input())
for M in range(m):
    name = input()
    klist.append(name)
data = MyRecipe(rlist,klist)
recipeName = input()
cnt = data.getRCount(recipeName)
if cnt is None:
    print("Major ingredients for given recipe type not found")
else:
    print(cnt)
arr = data.minCalorie()
for ele in arr:
    print(ele.ID)
    print(ele.name)
    print(ele.rtype)
    print(ele.calorie)

    