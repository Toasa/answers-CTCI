A = ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""]

def search(s):
    low = 0
    hi = len(A)

    while abs(low - hi) > 1:
        mid = (low + hi) // 2
        if A[mid] == s:
            return mid
        elif A[mid] == "":
            l = mid-1
            r = mid+1

            while 0 <= l or r < len(A):
                if 0 <= l and A[l] != "":
                    if A[l] == s:
                        return l
                    mid = l
                    break
                if r < len(A) and A[r] != "":
                    if A[r] == s:
                        return r
                    mid = r
                    break
                l -= 1
                r += 1
            return -1

        if A[mid] > s:
            hi = mid
        else:
            low = mid

    if A[low] == s:
        return low

    return -1

def main():
    print(search("at"))
    print(search("ball"))
    print(search("car"))
    print(search("dad"))

main()
