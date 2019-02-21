n = int(input())
l = set()
for i in range(n):
    l.add(input())
print("\n".join(sorted(l, key = lambda i : [len(i), i])))