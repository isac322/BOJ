l = input().split(':')
p = lambda x: print(x, end="")
if len(l[0]) is 0:
	l.remove(l[0])
if len(l[-1]) is 0:
	l.pop()
t = True
for s in l:
	if len(s) is 0:
		for _ in range(8 - len(l) + 1):
			if t:
				p("0000")
				t = False
			else:
				p(":0000")
	elif t:
		p("%04x" % int(s, 16))
		t = False
	else:
		p(":%04x" % int(s, 16))
