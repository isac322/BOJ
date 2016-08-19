def gcd(a, b):
    while b != 0:
        a, b = b, a%b
    return a

for _ in range(int(input())):
    a, b = input().split()
    a = int(a)
    b = int(b)
    print(a * b // gcd(a, b))