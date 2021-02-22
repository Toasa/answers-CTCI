class S:
    def __init__(self, s):
        self.s = s
        self.s_sorted = sorted(s)

def main():
    strs = ["banana", "annaba", "hom", "nabana", "dom", "omh"]
    Ss = []
    for s in strs:
        Ss.append(S(s))

    Ss = sorted(Ss, key=lambda s: s.s_sorted);

    for s in Ss:
        print(s.s)

main()
    
