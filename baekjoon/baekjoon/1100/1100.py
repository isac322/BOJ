cnt = 0
for i in range(8):
    l = input()
    for ch in range(i&1, 8, 2):
        if (l[ch] == 'F'):
            cnt += 1
print(cnt)