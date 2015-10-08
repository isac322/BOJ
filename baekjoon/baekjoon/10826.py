n = int(input())

p = 1
pp = 0
ppp = 0

for i in range(2, n + 1):
	ppp = p + pp
	pp = p
	p = ppp

if n is 0:
	print('0')
else:
	print(p)