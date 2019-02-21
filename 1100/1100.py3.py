l = []
cnt = 0
for i in range(8):
    l.append(input())
    if (i&1):
        for ch in range(1, 8, 2):
            if (l[i][ch] == 'F'):
                cnt += 1
    else:
        for ch in range(0, 8, 2):
            if (l[i][ch] == 'F'):
                cnt += 1
print(cnt)