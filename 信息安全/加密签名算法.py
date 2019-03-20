import pyDes
import base64
from Crypto.Cipher import AES
from binascii import b2a_hex, a2b_hex
from Crypto import Random
import hashlib
from Crypto.Cipher import PKCS1_v1_5 as Cipher_pkcs1_v1_5
from Crypto.Signature import PKCS1_v1_5 as Signature_pkcs1_v1_5
from Crypto.PublicKey import RSA

f=open('data.txt', 'r')
data = f.read()

# padding算法
BS = AES.block_size # aes数据分组长度为128 bit
pad = lambda s: s + (BS - len(s) % BS) * chr(0) 


def mdes(data):
	'''
	https://github.com/toddw-as/pyDes
	pyDes.des(key, [mode], [IV], [pad], [padmode])
	pyDes.triple_des(key, [mode], [IV], [pad], [padmode])
	key     -> Bytes containing the encryption key. 8 bytes for DES, 16 or 24 bytes
		   for Triple DES
	mode    -> Optional argument for encryption type, can be either
		   pyDes.ECB (Electronic Code Book) or pyDes.CBC (Cypher Block Chaining)
	IV      -> Optional Initial Value bytes, must be supplied if using CBC mode.
		   Length must be 8 bytes.
	pad     -> Optional argument, set the pad character (PAD_NORMAL) to use during
		   all encrypt/decrpt operations done with this instance.
	padmode -> Optional argument, set the padding mode (PAD_NORMAL or PAD_PKCS5)
		   to use during all encrypt/decrypt operations done with this instance.
	'''
	data = data.encode()
	k = pyDes.des(b"DESCRYPT", pyDes.CBC, b"AAAAAAAA", pad=None, padmode=pyDes.PAD_PKCS5)
	d = k.encrypt(data)
	print ("=== DES加密 ===")
	print ("明文:", data.decode())
	print ("密钥", b"DESCRYPT".decode())
	print ("偏转向量", b"AAAAAAAA".decode())
	print ("密文:", d)
	print ("base64:", base64.b64encode(d))
	print ("hex:", b2a_hex(d))
	print ("直接解密:", k.decrypt(d))
	print ("hex解密:", k.decrypt(a2b_hex(b2a_hex(d))))
	print ("base64解密:", k.decrypt(base64.b64decode(base64.b64encode(d))))
	assert k.decrypt(d) == data

def maes(data):
	iv = Random.new().read(AES.block_size)
	# AES key must be either 16, 24, or 32 bytes long
	k = AES.new("DESCRYPTDESCRYPT", AES.MODE_CBC, iv)
	d = iv + k.encrypt(pad(data))
	# 这里统一把加密后的字符串转化为16进制字符串
	print ("\n=== AES加密 ===")
	print ("明文:", data)
	print ("密钥:", "DESCRYPTDESCRYPT")
	print ("偏转向量", iv)
	print ("密文:", d)
	print ("hex:", b2a_hex(d))
	print ("base64:", base64.b64encode(d))
	iv =  d[0:AES.block_size]
	d = d[AES.block_size:len(d)]
	k = AES.new("DESCRYPTDESCRYPT", AES.MODE_CBC, iv)
	print ("解密:", k.decrypt(d).decode().rstrip(chr(0)))
	# 加密时补了'\0'，解密时应当去掉

def md5(data):
	data = data.encode()
	m = hashlib.md5()   
	m.update(data)
	print ("\n=== MD5 ===")
	print ("MD5:", m.hexdigest())

def sha1(data):
	data = data.encode()
	m = hashlib.sha1()   
	m.update(data)
	print ("\n=== sha1 ===")
	print ("sha1:", m.hexdigest())

def rsa(data):
	data = data.encode()
	# 伪随机数生成器
	random_generator = Random.new().read
	# rsa算法生成实例
	rsa = RSA.generate(1024, random_generator)
	private_pem = rsa.exportKey()
	public_pem = rsa.publickey().exportKey()
	rsakey = RSA.importKey(public_pem)
	cipher = Cipher_pkcs1_v1_5.new(rsakey)
	cipher_text = base64.b64encode(cipher.encrypt(data))
	rsakey = RSA.importKey(private_pem)
	cipher = Cipher_pkcs1_v1_5.new(rsakey)
	text = cipher.decrypt(base64.b64decode(cipher_text), random_generator)
	print ("\n=== RSA ===")
	print ("private_pem\n", private_pem.decode())
	print ("public_pem\n", public_pem.decode())
	print ("密文:", cipher_text.decode())
	print ("解密:", text.decode())

if __name__ == '__main__':
	mdes(data)
	maes(data)
	md5(data)
	sha1(data)
	rsa(data)