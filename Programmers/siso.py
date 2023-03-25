def check_c(c):
    return "a" <= c and c <= "z"


def gen_sets(str):
    sets = []
    f = True
    for idx in range(len(str) - 1):
        if f:
            if not check_c(str[idx]):
                continue
            f = False
        if not check_c(str[idx + 1]):
            idx += 1
            f = True
            continue
        sets.append(f"{str[idx]}{str[idx+1]}")
    return sorted(sets)


def solution(str1, str2):
    set1 = gen_sets(str1.lower())
    set2 = gen_sets(str2.lower())

    if len(set1) == 0:
        if len(set2) == 0:
            return 65536
        return 0

    n_inter = -1
    n_sum = -1
    c1 = " "
    c2 = " "
    while len(set1) != 0:
        if c1 == c2:
            c1 = set1.pop()
            c2 = set2.pop()
            n_inter += 1
        elif c1 > c2:
            c1 = set1.pop()
        elif c2 > c1:
            c2 = set2.pop()
        n_sum += 1
        if len(set2) == 0:
            set2 = set1
            c1, c2 = c2, c1
            set1 = []
    n_sum += len(set2)
    if c1 == c2 or c1 in set2:
        n_inter += 1
        n_sum += 1
    else:
        n_sum += 2
    return n_inter * 65536 // n_sum


print(solution("abc", "abbb"))
