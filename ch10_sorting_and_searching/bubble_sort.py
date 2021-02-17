def bubble_sort(A):
    l = len(A)
    for i in range (0, l-1):
        for j in range(l-1, i, -1):
            if A[i] > A[j]:
                A[i], A[j] = A[j], A[i]


def main():
    A = [1, 10, 3, 4, 56, 2, 8, 30, 20, 7]
    bubble_sort(A)
    print(A)

main()
