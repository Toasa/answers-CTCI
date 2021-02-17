def selection_sort(A):
    l = len(A)
    for i in range (0, l-1):
        cur_min = A[i]
        cur_min_i = i
        for j in range(i+1, l):
            if cur_min > A[j]:
                cur_min = A[j]
                cur_min_i = j
        if i != cur_min_i:
            A[i], A[cur_min_i] = A[cur_min_i], A[i]

def main():
    A = [1, 10, 3, 4, 56, 2, 8, 30, 20, 7]
    selection_sort(A)
    print(A)

main()
