n = int(input())
l = []
for i in range(n):
    l.append(input())
print("\n".join(sorted(set(l), key = lambda i : [len(i), i])))