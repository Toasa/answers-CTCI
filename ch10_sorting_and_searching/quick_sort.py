A = [10, 3, 4, 56, 2, 1, 8, 30, 20, 7]

def partition(l, r):
    pivot = r
    firsthigh = l

    # 分割は３つの区間を管理しながら行う
    # pivot より小さい区間: firsthigh の左側
    # pivot と同じかそれ以上の区間: firsthigh と i の間
    # 未調査の区間: i の右側

    for i in range(l, r):
        if A[i] < A[pivot]:
            A[i], A[firsthigh] = A[firsthigh], A[i]
            firsthigh += 1

    A[firsthigh], A[pivot] = A[pivot], A[firsthigh]
    return firsthigh

def quick_sort(l, r):
    if r - l > 0:
        p = partition(l, r)
        quick_sort(l, p - 1);
        quick_sort(p + 1, r);

def main():
    quick_sort(0, len(A)-1)
    print(A)

main()
