def main():
    input_ = ["Mr John Smith      ", 13]
    s = input_[0]
    s_len = input_[1]

    res = ""
    i = 0
    while i < len(s):
        c = s[i]
        if c == " ":
            if s_len > 0:
                res += "%20"
                s_len -= 1
                while i < len(s) and s[i] == " ":
                    i += 1
            else:
                i += 1
        else:
            s_len -= 1
            res += c
            i += 1
    
    print(res)

main()
