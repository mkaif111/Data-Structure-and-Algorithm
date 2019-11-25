t = int(input())




for _ in range(t):
    l = int(input())
    bob = []
    alice = []
    alice_word = []
    bob_word = []
    for i in range(26):
        alice_word.append(0)
        bob_word.append(0)

    for _ in range(l):
        s = input('')
        count_c = 0
        count_v = 0
        for i in s:
            if i in ['a','e','i','o','u']:

                count_v+=1
            else:
                count_c+=1
        if count_v >= count_c:
            mylist = []
            for wc in s:
                mylist.append(wc)
            for l in list(dict.fromkeys(mylist)):
                alice_word[ord(l)-97]+=1
            alice.append(s)

        else:
            mylist = []
            for wc in s:
                mylist.append(wc)
            for l in list(dict.fromkeys(mylist)):
                bob_word[ord(l)-97]+=1
            bob.append(s)
    # print(alice_word[:3] , bob_word[:3])

    alice_w = []
    for i in range(26):

        alice_w.append(0)
    # print(alice)
    for i in alice:
        for j in i:
            alice_w[ord(j)-97]+=1
    # print(alice_w[:3])
    alice_score = 1
    for i in range(26):
        if alice_w[i]!=0 and alice_word[i]!=0:
            alice_score*= alice_word[i]/pow(alice_w[i],2)
    # print(alice_score)

    bob_w = []
    for i in range(26):
        bob_w.append(0)
    for i in bob:
        for j in i:
            bob_w[ord(j)-97]+=1
    # print(bob_w[:3])
    bob_score = 1
    for i in range(26):
        if bob_w[i]!=0 and bob_word[i]!=0:
            bob_score *= bob_word[i]/pow(bob_w[i],2)
    # print(bob_score)
    if alice_score/bob_score< pow(10,7):

        print(round(alice_score/bob_score,10)
    else:
        
        print('Infinity')
