for j in range(int(input())):
	n, m = map(int, input().split())
	cnt = 0
	for i in range(n, m + 1):
		s = str(i)
		cnt += s.count('0')
	print(cnt)