import math
import random
def gcd(a,b):
    if b==0:return a
    else:return gcd(b,a%b)
def fermat(n,k):
    for i in range(k):
        b=random.randrange(2,n-1)
        d=gcd(n,b)
        if d!=1:
            return False
        if pow(b,n-1,n)!=1:
            return False
    return True
def get_q(m):
    q=0
    while m%2==0:
        q=q+1
        m=m/2
    return q
def get_m(m):
    while m%2==0:
        m=m/2
    return m

def Miller_Rabin(n,k):
    for i in range(k):
        a = random.randrange(2, n - 1)
        if pow(a,n-1,n)!=1:
            return False
        q=get_q(n-1)
        while q!=0:
            q=q-1
            if pow(a,int(get_m(n-1)*pow(2,q)),n)==n-1:
                break
        if pow(a,int(get_m(n-1)),n)!=0:
            continue
    return True

num=int(input("请输入待检测数"))
safenum=int(input("请输入安全参数"))
if fermat(num,safenum)==True&Miller_Rabin(num,safenum)==True:
    print("满足费马小定理和Miller-Rabin素性检验，因此极大可能是素数！！！")
else:
    print("这个数是合数！！！")
if fermat(num,safenum)==True&Miller_Rabin(num,safenum)==False:
    print("满足费马小定理，但不是素数，而是伪素数！！！")
