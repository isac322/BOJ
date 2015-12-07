t = []
s = ""
le = int(input())
for i in range(le):
    t.append(input())
for ii in range(len(t[0])):
    b = True
    for i in range(le):
        if t[0][ii] != t[i][ii]:
            b = False
    if b:
        s += t[0][ii]
    else :
        s += '?'
print(s)