from itertools import permutations
import enchant
s,n = raw_input().split()
#print(*[''.join(i) for i in permutations(sorted(s),int(n))],sep='\n')
res = [''.join(i) for i in permutations(sorted(s),int(n))]
d = enchant.Dict("en_US")
for i in res:
	if d.check(i):
		print i, '\n'