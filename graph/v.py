class Volcano:
    volcanoName = ""
    country = ""
    elevation = 0
    areaInKmSq = 0
    lastEruptionYear = 0
    def __init__(self,volcano_name,country,elevation,areaInKmSq,lastEruptionYear):
        
        self.volcanoName = volcano_name
        self.country = country
        self.elevation = elevation
        self.areaInKmSq = areaInKmSq
        self.lastEruptionYear = lastEruptionYear
class Eruption:
    volcano_list = []
    def findVolcanoByCountry(self,volcanoList,country):
        ans_list = []
        for vol in volcanoList:
            if (vol.country).upper() == country.upper():
                ans_list.append(vol)
        if len(ans_list)>0:
            return ans_list
        return None
    def getVolcanoCategorization(self,vol_obj,name):
        for vol in vol_obj:
            if vol.volcanoName.upper() == name.upper():
                year = abs(2021 - vol.lastEruptionYear)
                if 1<=year<25:
                    return "High probability"
                elif 25<=year<50:
                    return "Low probability"
                elif year == 0:
                    return "Active"
                else:
                    return "Inactive"
        return None

no_of_vol = int(input())
vol_list = []
for _ in range(no_of_vol):
    name = input()
    country = input()
    ele = int(input())
    area = int(input())
    year = int(input())
    vol = Volcano(name,country,ele,area,year)
    vol_list.append(vol)
    ct = input()
    vol = input()
    e = Eruption()
    l = e.findVolcanoByCountry(vol_list,ct)
    
    if l is  None:
        print("No Matching records")
    else:
        for v in l:
            print(v.volcano_name)
            print(v.country)
            print(v.lastEruptionYear)
    status = e.getVolcanoCategorization(vol_list,vol)
    if status:
        print(status)
    else:
        print("No volcano is available with given name")
    
    




















        