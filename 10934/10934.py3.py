import hashlib
print(hashlib.new('SHA', input().encode()).hexdigest())