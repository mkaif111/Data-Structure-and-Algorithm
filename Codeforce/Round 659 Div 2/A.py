import random
t = int(input())
for __ in range(t):

	n = int(input())
	arr = list(map(int,input().split()))
	ans = []
	max_len = 60
	ans.append('a'*60)
	alpha = ['a','b','c','d','e','f','g','h','i','j']
	index = 0
	for i in range(len(arr)):
		lcp = arr[i]
		match = ''
		if lcp!=0:
			match = ans[i][0:lcp]
		rem_str = ''
		for j in alpha:
			if j not in ans[i]:
				rem_str = j
		rem = rem_str*(60-len(match))
		index+=1
		ans.append(match+rem)
	for i in ans:
		print(i)

