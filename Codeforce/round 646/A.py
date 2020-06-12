t = int(input())

for T in range(t):
    n , m = map(int , input().split(" "))
    ans = (m*n)//2 + (m*n)%2
    # ans += (n%2)*(m//2 + (m%2))

    print(ans)