S = [15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14]

def bi_search(A, val):
    low = 0
    hi = len(A)

    while abs(low - hi) > 1:
        mid = (low + hi) // 2
        if A[mid] <= val:
            low = mid
        else:
            hi = mid

    if A[low] == val:
        return True, low
    else:
        return False, None

def main():
    min_val = 10**9
    min_i = 0
    for i, s in enumerate(S):
        if s < min_val:
            min_i = i
            min_val = s

    first_half = S[:min_i]
    second_half = S[min_i:]

    print(bi_search(first_half, 17))
    print(bi_search(second_half, 17))

main()

