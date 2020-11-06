# cook your dish here
import sys
import random


n = int(input())

y = random.randint(1,n)
sys.stdout.write(str(y))
sys.stdout.flush()

x = ''

while x !='E':
    x = input()
    sys.stdout.flush()
    if x=='E':
        break
    elif x=='L':
        y = random.randint(1,y)
        sys.stdout.write(str(y))
        sys.stdout.flush()
    else:
        y = random.randint(y,n)
        sys.stdout.write(str(y))
        sys.stdout.flush()