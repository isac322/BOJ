str = input().lower()
al = 'qwertyuiopasdfghjklzxcvbnm'
ch = []
for i in al:
    ch.append(str.count(i))
l = [(i, v) for i, v in enumerate(ch) if v == max(ch)]
if (len(l) > 1):
    print('?')
else:
    print(al[l[0][0]].upper())