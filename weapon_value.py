t = int(input())

for _ in range(t):
    n = int(input())
    s = []
    for i in range(n):
        s1 = input()
        s.append(s1)

    ans = []
    for i in range(10):
        ans.append(int(s[0][i])^int(s[1][i]))
    # print(ans)

    for i in range(2,len(s)):
        for j in range(10):
            ans[j] = ans[j]^int(s[i][j])
        # print(ans)
    print(sum(ans))
