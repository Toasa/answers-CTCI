SENTINEL_VAL = 10**9

def merge(left, right):
    result_len = len(left) + len(right)
    result = [0] * result_len
    left.append(SENTINEL_VAL)
    right.append(SENTINEL_VAL)
    l_i, r_i = 0, 0
    for i in range(result_len):
        if left[l_i] < right[r_i]:
            result[i] = left[l_i]
            l_i += 1
        else:
            result[i] = right[r_i]
            r_i += 1
    return result

def merge_sort(A):
    if len(A) <= 1:
        return A
    elif len(A) == 2:
        if A[0] > A[1]:
            A[0], A[1] = A[1], A[0]

    left = A[:len(A)//2]
    right = A[len(A)//2:]

    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)

def main():
    A = [1, 10, 3, 4, 56, 2, 8, 30, 20, 7]
    A_sorted = merge_sort(A)
    print(A_sorted)

main()
