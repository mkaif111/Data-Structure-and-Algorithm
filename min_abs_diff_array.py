n= int(input())

arr1 = input()
arr1 = arr1.strip()
arr1 = arr1.split(" ")

arr=[]
for i in arr1:
    arr.append(int(i))

arr.sort()

min_v = 1000000007

for i in range(0,n-1):
    if abs(arr[i]-arr[i+1])<=min_v:
        min_v = abs(arr[i]-arr[i+1])

print(min_v)
