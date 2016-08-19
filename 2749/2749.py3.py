
def fibonacci(n):
	if n == 0:
		return 0, 1
	else:
		a, b = fibonacci(n // 2)
		c = a * (b * 2 - a)
		d = a * a + b * b
		if n % 2 == 0:
			return c % 1000000, d % 1000000
		else:
			return d % 1000000, (c + d) % 1000000

print(fibonacci(int(input()))[0])
