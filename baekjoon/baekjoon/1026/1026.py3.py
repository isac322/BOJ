s=0
t=lambda:list(map(int,input().split()))
n=int(input())
a=t();b=t();a.sort();b.sort();b.reverse()
for i in range(n):s+=a[i]*b[i]
print(s)