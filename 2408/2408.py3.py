t = ""
for _ in range(2 * int(input()) - 1):
	t += input()
print(eval(t.replace('/', '//')))
