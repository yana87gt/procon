def check(s1,s2):
    l1 = s1.split('"')
    l2 = s2.split('"')
    if len(l1) != len(l2):
        return "DIFFERENT"
    close = 0
    for i in range(len(l1)):
        if l1[i] != l2[i]:
            if i % 2 == 0: return "DIFFERENT"
            else : close += 1
    if close == 1: return "CLOSE"
    if close == 0: return "IDENTICAL"
    return "DIFFERENT"

if __name__ == '__main__':
    while True:
        s1 = input()
        if s1 == ".": break
        s2 = input()
        print(check(s1,s2))