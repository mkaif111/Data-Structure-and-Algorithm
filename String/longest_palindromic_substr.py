
s = input()
n = len(s)
max_l = 0
count = 0
for i in range(n):
    # even length 
    l=i
    r=i+1
    curr_l = 0
    while l>=0 and r<n and s[l]==s[r]:
        curr_l = r-l+1
        count+=1
        if(curr_l>max_l):
            max_l = curr_l
        l-=1
        r+=1
    # odd length
    l=i
    r=i
    curr_l = 0
    while l>=0 and r<n and s[l]==s[r]:
        curr_l = r-l+1
        count+=1
        if(curr_l>max_l):
            max_l = curr_l
        l-=1
        r+=1
#no. of palindrome string 
print(count)
#Max length Palindrome String
print(max_l)