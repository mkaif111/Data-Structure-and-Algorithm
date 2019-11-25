def digits(n):
    if n==0:
        return
    digits(n//10)
    print(str(n%10) + "-->",end=" ")

n = int(input("enter the number : "))
digits(n)
