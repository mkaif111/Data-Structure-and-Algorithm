
digit = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]

def print_s(n,output):
    if n==0 or n==1:
        print(output)
        return
    input = digit[n%10]
    n = n//10
    for i in input:
        print_s(n , i+output)


def keypad(num):
    if num==0 or num==1:
        return;
    input = digit[num%10]
    num =num//10
    for i in input:
        print_s(num,i)





n = int(input())

keypad(n)
