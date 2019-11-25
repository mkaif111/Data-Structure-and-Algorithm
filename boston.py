import math
def primeFactors(n):
    sum_p=0

    # Print the number of two\'s that divide n
    while n % 2 == 0:
        sum_p+=2
        n = n / 2

    # n must be odd at this point
    # so a skip of 2 ( i = i + 2) can be used
    for i in range(3,int(math.sqrt(n))+1,2):

        # while i divides n , print i ad divide n
        while n % i== 0:
            x = i
            while x>0:
                sum_p+=x%10
                x=x//10

            n = n / i

    # Condition if n is a prime
    # number greater than 2
    if n > 2:
        x=n
        while x>0:
            sum_p+=x%10
            x=x//10
    return sum_p


def dig(n):
  num = []
  while n>0:
      num.append(n%10)
      n = n//10
  return num


n = int(input())
#
# print("digits sum" ,sum(dig(n)))
# print("prime factors sum" ,primeFactors(n))
sum_digit = sum(dig(n))
sum_pf = primeFactors(n)
if sum_digit==sum_pf:
    print(1)
else:
    print("0")
