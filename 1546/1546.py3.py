a = int(input())
c = list(map(int, input().split()))
d = max(c)
e = 0
for g in c:
    e=e+g/d
print("{0:.2f}".format(e/a*100))