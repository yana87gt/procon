T = int(input())
for i in range(T):
    x = input()
    s = input()
    r = ""
    for c in s:
        if c == 'S': r += 'E'
        else: r += 'S'
    print("Case #{}: {}".format(i+1, r))
