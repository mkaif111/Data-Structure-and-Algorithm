while True:
    ch = input("")
    if ch=="+":
        n1 = int(input())
        n2 = int(input())
        print(n2+n1)
    elif ch=="-":
        n1 = int(input())
        n2 = int(input())
        print(n1-n2)
    elif ch=="*":
        n1 = int(input())
        n2 = int(input())
        print(n1*n2)
    elif ch=="/":
        n1 = int(input())
        n2 = int(input())
        print(n1/n2)
    elif ch=="%":
        n1=int(input())
        n2=int(input())
        print(n1%n2)
    elif ch=="x" or ch=="X":
        break
    else:
        print("Invalid operation. Try again.")
