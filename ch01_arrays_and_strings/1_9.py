def is_substring(s1, s2):
    return s1 in s2

def is_rotation(s1, s2):
    return is_substring(s1, s2+s2)

def main():
    s1 = "waterbottle"
    s2 = "erbottlewat"
    print(is_rotation(s1, s2))

main()
