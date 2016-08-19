t = int(input())
for i in range(t):
    lst = input().split()
    print(str(bin(int(lst[0],2) + int(lst[1],2)))[2:])