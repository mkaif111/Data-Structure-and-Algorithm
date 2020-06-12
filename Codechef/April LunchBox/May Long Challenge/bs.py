from itertools import combinations 

# Fills Z array for given string str[] 
def getZarr(string, z): 
    n = len(string) 
  
    # [L,R] make a window which matches 
    # with prefix of s 
    l, r, k = 0, 0, 0
    for i in range(1, n): 
  
        # if i>R nothing matches so we will calculate. 
        # Z[i] using naive way. 
        if i > r: 
            l, r = i, i 
  
            # R-L = 0 in starting, so it will start 
            # checking from 0'th index. For example, 
            # for "ababab" and i = 1, the value of R 
            # remains 0 and Z[i] becomes 0. For string 
            # "aaaaaa" and i = 1, Z[i] and R become 5 
            while r < n and string[r - l] == string[r]: 
                r += 1
            z[i] = r - l 
            r -= 1
        else: 
  
            # k = i-L so k corresponds to number which 
            # matches in [L,R] interval. 
            k = i - l 
  
            # if Z[k] is less than remaining interval 
            # then Z[i] will be equal to Z[k]. 
            # For example, str = "ababab", i = 3, R = 5 
            # and L = 2 
            if z[k] < r - i + 1: 
                z[i] = z[k] 
  
            # For example str = "aaaaaa" and i = 2,  
            # R is 5, L is 0 
            else: 
  
                # else start from R and check manually 
                l = i 
                while r < n and string[r - l] == string[r]: 
                    r += 1
                z[i] = r - l 
                r -= 1
  
# prints all occurrences of pattern  
# in text using Z algo 
def search(text, pattern): 
  
    # Create concatenated string "P$T" 
    concat = pattern + "$" + text 
    l = len(concat) 
  
    # Construct Z array 
    z = [0] * l 
    getZarr(concat, z) 
    count=0
    
    for i in range(l): 
  
        
        if z[i] == len(pattern): 
            count=count+1
    return count
             

def allsubstr(s):
    res = [s[x:y] for x, y in combinations( 
            range(len(s) + 1), r = 2)] 
    
    return res


t = int(input())

for _ in range(t):

    A = input()
    B = input()
    n = int(input())
    dic = {}
    min_length = -1
    for __ in range(n):
        inp = input().rstrip().split(" ")
        num = int(inp[1])
        dic[inp[0]] = num
        if len(inp[0])<min_length or min_length==-1:
            min_length = len(inp[0])
    
    a = allsubstr(A)
    b = allsubstr(B)
    print(a, len(a))
    print(b, len(b))
    
    substr = a+b
    
    # for i in a:
    #     for j in b:
    #         if(len(i+j)>=min_length):
    #             substr.append(i+j)
    print(substr)
    # print(len(substr))
    # if "techechef" in substr:
    #     print("yeah")
    max_ans = -1
    for s in substr:
        sum_b = 0
        for string,value in sorted(dic.items(),key = lambda x:x[1]):
            if string in s:

                rep = search(s,string)
                # print(string,rep)
                sum_b +=rep*value
        
        if max_ans<sum_b:
            max_ans = sum_b

    print(max_ans)




