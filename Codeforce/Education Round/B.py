t = int(input())

for _ in range(t):
    s = input()
    if '0' not in s or '1' not in s:
        print(s)
    else:
        if s[0]=='0':
            for i in range(len(s)):
                print("01",end="")
            print()
        else:
            for i in range(len(s)):
                print("10",end="")
            print()




