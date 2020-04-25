

def getlps(s):
    arr = [0]*len(s)
    i=1
    j=0
    arr[0]=0
    while i<len(s):
        if s[i]==s[j]:
            arr[i] = j + 1
            i+=1
            j+=1
        else:
            if j!=0:
                j = arr[j-1]
            else:
                arr[i] = 0
                i+=1
    return arr

def kmp(s,p):
    
    lps = getlps(p)
    i=0
    j=0
    
    
    while i<len(s) and j<len(p):
        if j==len(p):
            return i+1
        if p[j]==s[i]:
            i+=1
            j+=1
        else:
            if j!=0:
                j = lps[j-1]
            else:
                i=i+1
    if j==len(p):
        return i-j
    return -1

t = input()
p = input()
print(kmp(t,p))
    
    
        
