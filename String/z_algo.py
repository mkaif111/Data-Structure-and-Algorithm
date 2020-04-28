def z_build(s):
    n = len(s)
    l=0
    r=0
    z = [0]*n
    for i in range(1,n):
        if i>r:
            l=r=i
            while r<n and s[r]==s[r-l]:
                r+=1
            z[i] = r-l
            r-=1
        else:
            k = i-l
            if z[k]+i<=r:
                z[i]=z[k]
            else:
                l = i
                while r<n and s[r]==s[l]:
                    r+=1
                z[i] = r-l
                r-=1
    return z


text = input("text : ")
pattern = input("pattern : ")
delimeter = "$"
s = pattern+delimeter+text

z = z_build(s)
p_len = len(pattern)

for i in range(len(s)):
    if z[i]==p_len:
        print(f"Pattern found at {i-p_len}th index of text")