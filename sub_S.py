#subsets of strings
def print_S(s , curr="",index =0):
    if index ==len(s):
        if curr== "":
            return ;
        else:
            print(curr,end=" ")
            return;
    print_S(s, curr , index+1 )
    print_S(s, curr+s[index],index+1)

s =input("enter the string")
print_S(s)
