import re

def solve():
    N = int(input())
    P = [input() for i in range(N)]
    max_left = ""
    max_right = ""
    for i in range(N):
        sp = P[i].split('*')
        if len(max_left) < len(sp[0]):
            max_left = sp[0]
        if len(max_right) < len(sp[-1]):
            max_right = sp[-1]
    
    for k in range(len(max_right)+1):
        res = max_left + max_right[k:]
        ng = False
        for i in range(N):
            if re.fullmatch(r'{}'.format(P[i].replace('*', '.*')), res) is None:
                ng = True
        if not ng and len(res) <= 10000:
            print(res)
            return
    print("*")

if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        print("Case #{}: ".format(t+1),end='')
        solve()
