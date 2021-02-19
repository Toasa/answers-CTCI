A = [1, 2, 3, 4, 7, 8, 10, 20, 30, 56]

# [low, hi) の区間で探索
def bi_search(val):
    low = 0
    hi = len(A)

    while abs(low - hi) > 1:
        mid = (low + hi) // 2
        if A[mid] == val:
            return True, mid
        elif A[mid] < val:
            low = mid + 1
        else:
            hi = mid

    if A[low] == val:
        return True, low
    else:
        return False, None


# # [low, hi) の区間で探索
# def bi_search(low, hi, val):
#     mid = (low + hi) // 2
# 
#     if A[mid] == val:
#         return True, mid
# 
#     if abs(hi - low) <= 1:
#         return False, None
# 
#     if A[mid] < val:
#         return bi_search(mid+1, hi, val)
#     else:
#         return bi_search(low, mid, val)

def main():
    print(bi_search(1))
    print(bi_search(2))
    print(bi_search(3))
    print(bi_search(4))
    print(bi_search(5))
    print(bi_search(6))
    print(bi_search(7))

main()
