def Rotate(arr, d):
    # Please add your code here
    store = []
    for i in range(d):
        x = arr.pop(0)
        arr.append(x)
    return arr

# Main
n=int(input())
arr=list(int(i) for i in input().strip().split(' '))
d=int(input())
Rotate(arr, d)
print(*arr)
