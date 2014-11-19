def f(a, cnt, h):
    if a == 1:
        # print(h)
        return h
    if a % 2 == 0:
        return f(a // 2, cnt + 1, h)
    else:
        return f(a * 3 + 1, cnt + 1, max(h, a * 3 + 1))

opt = -1
for i in range(1, 10001):
    temp = f(i, 0, i)
    if temp > opt:
        print(temp)
        opt = temp

print(opt)
