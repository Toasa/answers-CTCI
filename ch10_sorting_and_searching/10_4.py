def element_at(i):
    if i < 55:
        return 1
    else:
        return -1

def get_size():
    r = 1
    while element_at(r) == 1:
        r *= 2

    l = 0
    while abs(l - r) > 1:
        mid = (l + r) // 2
        if element_at(mid) == -1:
            r = mid
        else:
            l = mid

    return r

def main():
    size = get_size()
    # size がわかったので二分探索すればよい

main()

