length = int(input())
l = list(map(int, input().split()))
m = max(l)
s = sum(l)
print("{0:.2f}".format(s/length/m*100))