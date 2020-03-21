#longest common subsequence


def lcs(s1,s2):
    if s1=='' or s2 =='':
        return 0
    if s1[0] == s2[0]:
        return 1+lcs(s1[1:],s2[1:])
    else:
        option1 = lcs(s1,s2[1:])
        option2 = lcs(s1[1:],s2)

        return max(option1,option2)

def lcs2(s1,s2,dp):
    if s1=='' or s2 =='':
        return 0
    if dp[len(s1)][len(s2)]>-1:
        return dp[len(s1)][len(s2)]
    ans = 0
    if s1[0]==s2[0]:
        ans = 1+lcs2(s1[1:],s2[1:],dp)
    else:
        option1 = lcs2(s1[1:],s2,dp)
        option2 = lcs2(s1,s2[1:],dp)
        ans = max(option1,option2)
        dp[len(s1)][len(s2)] = ans

    return ans


s1 = input()
s2 = input()

dp = [-1]*(len(s1)+1)
for i in range(len(s1)):
    dp[i] = [-1]*(len(s2)+1)
print(dp)





# abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef
# 111111111111111111111111111111111111111111111111

print(lcs2(s1,s2,dp))
print(lcs(s1,s2))
