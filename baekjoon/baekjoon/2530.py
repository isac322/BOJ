h, m, t = map(int, input().split())
c = int(input())
c += h*3600 + m*60 + t
t = c%60
c //= 60
m = c%60
c //= 60
h = c%24
print(h, m, t)