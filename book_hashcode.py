import operator
file1 = open("output2.txt","w")
file2 = open("b_read_on.txt")


b , l ,d = map(int,input().split())

print(f"books : {b} , lib : {l} , d : {d}")

score = [int(i) for i in input().split()]
print(score)

lib = {}

for i in range(l):

    n, t , m = map(int,input().split(" "))

    book_id = list(map(int,input().split(" ")))
    book_id_score = [0]*n

    for index in range(n):
        book_id_score[index] = score[book_id[index]]

    book_index_score  = {}
    for ind in range(n):
        book_index_score[book_id[ind]] = score[book_id[ind]]
    lib[sum(book_id_score)] = (i,book_id,book_index_score , t , m)

#sort by sum of book score in library descending order
sort_lib = sorted(lib.items(), key=operator.itemgetter(1))
print(sort_lib)
# file1.write(str(len(sort_lib))+"\n")
no_of_lib = 0
line=''
for key,data in sort_lib:
    if d<=0:
        break
    d = d-data[3]

    book_issue = 0
    if d*data[-1]>=len(data[1]):
        book_issue = len(data[1])
    else :
        book_issue = d*data[-1]
    if book_issue>0:
        print(data[0] , book_issue )
        line+=str(data[0])+" "+str(book_issue)+"\n"
        book = sorted(data[2].items(), key=operator.itemgetter(1),reverse=True)

        for id,_ in book:
            if book_issue==0:
                break
            print(id,end=" ")
            line+=str(id)+ " "

            book_issue-=1
        line+="\n"


        print()
    # if d<=0:
    #     break
    no_of_lib+=1
file1.write(str(no_of_lib)+"\n")
file1.writelines(line)
file1.close()
