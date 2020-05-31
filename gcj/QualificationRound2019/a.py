def solve(x):
    a = [int(ch) for ch in str(x//2)]
    b = [int(ch) for ch in str((x+1)//2)]
    for i in range(len(a)):
        if a[-i] == 4 or b[-i] == 4:
            a[-i] -= 1
            b[-i] += 1
    return ''.join(map(str,a)), ''.join(map(str,b))

if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        x = int(input())
        a, b = solve(x)
        print("Case #{}: {} {}".format(i+1, a, b))