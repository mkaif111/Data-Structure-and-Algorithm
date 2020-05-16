t = int(input())

for ___ in range(t):
    n = int(input())
    arr = [int(i) for i in input().split(" ")]
    l=1
    r=n-1
    previous = arr[0]
    alice=previous
    bob = 0
    alice_move = 1
    bob_move = 0
    count=1
    while(l<r):
        curr=0
        
        while(curr<previous and l<=r):
            curr+=arr[r]
            bob_move+=1
            r-=1
        if curr>=previous:
            count+=1
        else:
            break
        previous=curr
        bob+=curr
        curr=0
        while(curr<previous and l<=r):
            curr+=arr[l]
            alice_move+=1
            l+=1
        alice+=curr
        previous = curr
        if curr>=previous:
            count+=1
        else:
            break;
    print("anser")
    print(count,alice,bob)


