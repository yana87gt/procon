s = input()
res = ""
for c in s:
    if c == '1':
        res += '9'
    elif c == '9':
        res += '1'
    else:
        res += c
print(res)