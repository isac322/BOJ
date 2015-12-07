import base64
print(str(base64.b32encode(input().encode()), 'ascii'))