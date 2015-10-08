h, m = map(int, input().split())
t = int(input())

t += m
m = t % 60
t -= t % 60
t //= 60
h += t
h %= 24

print(h, m)