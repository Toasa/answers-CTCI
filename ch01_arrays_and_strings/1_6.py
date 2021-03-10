def try_compress(s):
    if len(s) <= 1:
        return s

    comp_s = ""

    #
    # aabcccccaaa
    #    ^   ^
    #    i   j
    #
    i, j = 0, 0
    while i < len(s):
        while j + 1 < len(s) and s[i] == s[j + 1]:
            j += 1

        comp_s += (s[i] + str(j - i + 1))
        j += 1
        i = j

    return comp_s if len(comp_s) < len(s) else s

def main():
    strs = ["aabcccccaaa", "abbXXXXXXXXXXXX", "abbX"]
    expects = ["a2b1c5a3", "a1b2X12", "abbX"] 

    for i, s in enumerate(strs):
        cs = try_compress(s)
        if expects[i] == cs:
            print("{} => {}".format(s, cs))
        else:
            print("{} expected but got {}".format(expects[i], cs))


    print("OK")
    
main()
