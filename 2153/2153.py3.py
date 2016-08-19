st = input()
sum = 0
for s in st:
    t = ord(s)
    if t >= ord('a'):
        sum += t - ord('a') + 1
    else:
        sum += t - ord('A') + 27
ii = 2
for i in range(2, sum + 1):
    if sum % i == 0:
        ii = i
        break
if ii == sum or sum == 1 :
    print('It is a prime word.')
else :
    print('It is not a prime word.')