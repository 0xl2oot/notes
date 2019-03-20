with open('data.txt','r') as f:
    data = f.read()
    print('明文：', data)

def encodeVigenere(s, e):
    return ' '.join("{:02x}".format((ord(c)+ord(e[idx%len(e)]))%256) for idx,c in enumerate(s))

def decodeVigenere(s, e):
    return ''.join(chr((ord(c)-ord(e[idx%len(e)]))%256) for idx,c in enumerate(s))

e = 'abcdefgh'
print('密码：', e)

cipher = encodeVigenere(data, e)
print('密文：', cipher)

with open('encode.txt','wb') as f:
    f.write((cipher.encode()))

with open('encode.txt','rb') as f:
    cipher = f.read().decode()
cipher = ''.join(chr(int('0x'+val, 16)) for val in cipher.split())
d = decodeVigenere(cipher, e)
print('解密：', d)