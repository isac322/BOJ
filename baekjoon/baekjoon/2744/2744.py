st = input()
for s in st:
    if ord(s) >= ord('a') :
        print(chr(ord(s) - 32), end = '')
    else :
        print(chr(ord(s) + 32), end = '')