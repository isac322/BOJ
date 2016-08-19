import hashlib
print(hashlib.new('RIPEMD160', input().encode()).hexdigest())