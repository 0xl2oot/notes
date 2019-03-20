from Crypto.Random import random
from Crypto.PublicKey import DSA
from Crypto.Hash import SHA
with open('data.txt', 'rb') as f:
    message=f.read()
key = DSA.generate(1024)
h = SHA.new(message).digest()
k = random.StrongRandom().randint(1,key.q-1)
sig = key.sign(h,k)
with open('encode.txt', 'wb') as m:
    m.write(b"Message: ")
    m.write(message)
    m.write(b"\nsignature: ")
    m.write(str(sig).encode())
    #签名的验证
    if key.verify(h, sig):
        m.write(b"\nSignature verification is true")
    else:
        m.write(b"\nSorry,signature verification is false")
