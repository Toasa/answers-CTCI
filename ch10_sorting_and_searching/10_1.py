A = [2, 3, 5, 6, 10, 13, 23, 38, 0, 0, 0, 0, 0, 0, 0]
B = [0, 1, 11, 14, 15, 40, 45]

def main():
    len_A = len(list(filter(lambda x: x != 0, A)))
    a_i, b_i = len_A-1, len(B)-1

    for i in range(len(A)-1, -1, -1):
        if b_i < 0 or A[a_i] > B[b_i]:
            A[i] = A[a_i]
            a_i -= 1
        else:
            A[i] = B[b_i]
            b_i -= 1

    if b_i >= 0:
        for i in range(b_i+1):
            A[i] = B[i]

    print(A)

main()
