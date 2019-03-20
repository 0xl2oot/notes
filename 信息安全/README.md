## 实验一：实现Vigenere密码算法

```c
#include<stdio.h>
#include<stdlib.h>
int i,j;
FILE *fp2,*fp1;
int Vigenere(char key[],char in[],int m)
{
    int keychange[6];
    int after[30];
    j=0;
    for(i=0;i<m;i++)
       {
           if(in[i]!='\0')
            j++;
       }
    int k=j;
    //记录密钥下标数字
    for(i=0;i<6;i++)
        keychange[i]=key[i];
    int l=j/6;
    for(j=0;j<l;j++)//组
    for(i=6*j;i<6+6*j;i++)//6个
        after[i]=(in[i]+keychange[i%6])%256;
    j=k%6;//余数部分
    for(i=6*l;i<6*l+j;i++)
        after[i]=(in[i]+keychange[i%6])%256;
    for(i=0;i<k;i++)
    {
        fprintf(fp2,"%4x",after[i]);
         in[i]=after[i];
    }
    fprintf(fp2,"\n");
    return k;
}
int Vigenerereverse(char key[],char in[],int m)
{
    int keychange[6];
    int after[30];
    j=0;
    for(i=0;i<m;i++)
       {
           if(in[i]!='\0')
            j++;
       }
    int k=j;
    for(i=0;i<6;i++)
        keychange[i]=key[i];
    for(i=0;i<j;i++)
        after[i]=in[i];
    m=j/6;
    for(j=0;j<m;j++)//五组
    for(i=6*j;i<6+6*j;i++)//6个
        after[i]=(after[i]+256-keychange[i%6])%256;
    j=k%6;//余数部分
    for(i=6*m;i<6*m+j;i++)
        after[i]=(after[i]+256-keychange[i%6])%256;
    for(i=0;i<k;i++)
        fprintf(fp2,"%c",after[i]);
    fprintf(fp2,"\n");
}
int main()
{
    int k,m;
    char out[30];
    char in[30];
    FILE *fp1 = fopen("C:\\Users\\tingyu\\Documents\\input.txt","r");
    fscanf(fp1,"%s",in);
    char key[6]="cipher";
    fp2 = fopen("C:\\Users\\tingyu\\Documents\\output.txt","wt");
    fprintf(fp2,"密钥:cipher\n");
    fprintf(fp2,"Vigenere加密后(以16进制存储ASCII码)\n");
    m=Vigenere(key,in,30);
    fprintf(fp2,"Vigenere解密后\n");
    Vigenerereverse(key,in,m);
    fclose(fp2);
}
运行结果：
密钥:cipher
Vigenere加密后(以16进制存储ASCII码)
  cb  ce  dc  d4  d4  92  da  d8  e2  d4  c9
Vigenere解密后
hello world
```

## 实验二：验证DES对称加密算法

```python
import base64
from pyDes import *
with open('2.txt', 'rb') as f:
    data=f.read()
Des_Key = b"BHC#@*UM" # Key
Des_IV = b"asdfghjk" # 自定IV向量
def DesEncrypt(data):
  k = des(Des_Key, CBC, Des_IV, pad=None, padmode=PAD_PKCS5)
  EncryptStr = k.encrypt(data)
  with open('des.txt', 'wb') as m:
      m.write(b"key:")
      m.write(Des_Key)
      m.write(b"\nIV:")
      m.write(Des_IV)
      m.write(b"\nmessage:")
      m.write(data)
      m.write(b"\nencrypt:")
      m.write(base64.b64encode(EncryptStr))
      m.write(b"\ndecrypt:")
      m.write(k.decrypt(EncryptStr))
DesEncrypt(data)
运行结果
key:BHC#@*UM
IV:asdfghjk
message:the best is yet to come
encrypt:idfU6zQlZa1aTnsInxs4ijoEkcy4Y19+
decrypt:the best is yet to come
```



## 实验三：验证RSA加密算法

```python
#p q两个质数 a是给的 RSA算法
import random
p=19
q=31
x=35
n=p*q
Q=(p-1)*(q-1)
def range_prime(start, end):
    l = list()
    for i in range(start, end+1):
        flag = True
        for j in range(2, i):
            if i % j == 0:
                flag = False
                break
        if flag:
            l.append(i)
    return l
#产生公钥
def relatively_prime():
    numbers=range_prime(10,100)
    set={1,2,3,4,5,6,7,8,9,10,11}
    for b in numbers:
        if Q%b>0 and b<Q:
            return b
b=relatively_prime()
# 产生私钥
for a in range(2,Q):
    flag=0
    if (b*a)%Q==1:
        flag=1
        break
    if(flag):
         break
def encrypt(x,a):
     y=pow(x,a)%n
     return y
with open('rsa.txt', 'wb') as m:
      m.write(b"public key:")
      m.write(str(b).encode())
      m.write(b"\nprivate key:")
      m.write(str(a).encode())
      m.write(b"\nmessage:")
      m.write(str(x).encode())
      m.write(b"\nencrypt:")
      m.write(str(encrypt(x,b)).encode())
      m.write(b"\ndecrypt:")
      m.write(str(encrypt(encrypt(x,b),a)).encode())
运行结果
public key:11
private key:491
message:35
encrypt:66
decrypt:35
```



## 实验四：验证MD5密码算法

```python
import hashlib
import base64
with open('message.txt', 'rb') as f:
    s=f.read()
with open('md5.txt', 'wb') as m:
    m.write(b"message:")
    m.write(s)
    m.write(b"\nMD5 process result:")
    m.write(hashlib.md5(s).hexdigest().encode())
运行结果
message:Yuan Tingyu
MD5 process result:104bbe147728b8294b2a060b3013b26f
```



## 实验五：验证DSS密码算法

```
#encoding utf-8
from Crypto.Random import random
from Crypto.PublicKey import DSA
from Crypto.Hash import SHA
with open('message.txt', 'rb') as f:
    message=f.read()
key = DSA.generate(1024)
h = SHA.new(message).digest()
k = random.StrongRandom().randint(1,key.q-1)
sig = key.sign(h,k)
with open('des.txt', 'wb') as m:
    m.write(b"Message: ")
    m.write(message)
    m.write(b"\nsignature: ")
    m.write(str(sig).encode())
    #签名的验证
    if key.verify(h, sig):
        m.write(b"\nSignature verification is true")
    else:
        m.write(b"\nSorry,signature verification is false")
运行结果：
Message: Hello World
signature: (224479245506364713163357251403811627047145704857, 85196154184555097949298891880297424856265656327)
Signature verification is true
```







