t = lambda: int(input())
n = t()
for i in range(n):
    m = t()
    o = t()
    for j in range(o):
        a, b = tuple(input().split())
        m += int(a)*int(b)
    print(m)
