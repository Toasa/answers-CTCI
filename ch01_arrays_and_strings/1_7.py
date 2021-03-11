def print_arr(A):
    for row in A:
        print(row)

def rotate_90_naive(A):
    size = len(A)
    res = [[0] * size for _ in range(size)]

    for i in range(size):
        for j in range(size):
            res[size-1-j][i] = A[i][j]
    return res

def rotate_90(A):
    size = len(A)

    # transpose
    for i in range(size):
        for j in range(i+1, size):
            A[i][j], A[j][i] = A[j][i], A[i][j]

    # reverse
    for i in range(size//2):
        for j in range(size):
            A[i][j], A[size-(i+1)][j] = A[size-(i+1)][j], A[i][j]

    return A

def main():
    A = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]

    print_arr(A)
    print_arr(rotate_90(A))
    print_arr(rotate_90_naive(A))

main()

