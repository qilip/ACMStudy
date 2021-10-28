import hashlib

n = input()
sha = hashlib.new('sha')
sha.update(n.encode('utf-8'))
ans = sha.hexdigest()
print(ans)
