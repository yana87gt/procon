def gcd(a,b): 
    if b == 0: return a
    else: return gcd(b, a%b)

def solve():
    N, L = map(int, input().split())
    a = list(map(int, input().split()))
    p = [0] * (L+1)

    for i in range(L-1):
        if a[i] != a[i+1]:
            p[i+1] = gcd(a[i], a[i+1])
            for j in range(i+1, 0, -1):
                p[j-1] = a[j-1]//p[j]
            for j in range(i+1, L):
                p[j+1] = a[j]//p[j]
            break
    ls = sorted(list(set(p)))
    num2alpha = {}
    for i, x in enumerate(ls):
        num2alpha[x] = chr(ord('A')+i)
    res = ""
    for x in p:
        res += num2alpha[x]
    return res

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        print("Case #{}: {}".format(i+1, solve()))
