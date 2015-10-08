len = int(input())
while len:
    n, st = input().split()
    n = int(n)
    for i in st:
        print(i*n, end = "")
    print("")
    len -= 1