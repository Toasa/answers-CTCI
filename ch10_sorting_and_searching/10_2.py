def main():
    strs = ["banana", "annaba", "hom", "nabana", "dom", "omh"]

    strs = sorted(strs, key=lambda s: sorted(s))
    for s in strs:
        print(s)

main()
    
