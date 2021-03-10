def is_replace_char(s1, s2):
    if len(s1) != len(s2):
        return False

    replaced = False

    for i, c1 in enumerate(s1):
        c2 = s2[i]
        if c1 != c2:
            if replaced:
                return False
            replaced = True
    return True

def is_insert_char(s1, s2):
    if len(s1)+1 != len(s2):
        return False

    inserted = False
    s1_i = 0
    s2_i = 0
    while s1_i < len(s1) and s2_i < len(s2):
        if s1[s1_i] != s2[s2_i]:
            if inserted:
                return False
            inserted = True
            s2_i += 1
            if s1[s1_i] != s2[s2_i]:
                return False

        s1_i += 1
        s2_i += 1

    return True

#    f?
# s1 ==> s2
#
# f is one of the following.
#    1. insert char
#    2. remove char
#    3. replace char
#
# If we solve this problem in one path,
# we should use Levenshtein distance.
def is_one_away(s1, s2):
    if s1 == s2:
        return True

    if len(s1) == len(s2):
        return is_replace_char(s1, s2)

    elif len(s1) + 1 == len(s2):
        return is_insert_char(s1, s2)

    elif len(s1) == len(s2) + 1:
        # Removing one charactor is convert
        # to inserting one charactor.
        return is_insert_char(s2, s1)

    else:
        return False

def main():
    s1_1, s1_2 = "pale", "ple"
    s2_1, s2_2 = "pales", "pale"
    s3_1, s3_2 = "pale", "bale"
    s4_1, s4_2 = "pale", "bake"
    print(is_one_away(s1_1, s1_2))
    print(is_one_away(s2_1, s2_2))
    print(is_one_away(s3_1, s3_2))
    print(is_one_away(s4_1, s4_2))

main()

