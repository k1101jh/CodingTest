A = str(input())
B = str(input())

vowels = ['a', 'e', 'i', 'o', 'u']

def get_sub_name(s):
    vowel_found = False
    idx = 0
    for i in range(len(s)):
        if s[i] in vowels:
            vowel_found = True
        elif vowel_found:
            idx = i
            break
    return s[:idx]

A_sub = get_sub_name(A)
B_sub = get_sub_name(B)

if A_sub == "" or B_sub == "":
    print("no such exercise")
else:
    print(A_sub + B_sub)