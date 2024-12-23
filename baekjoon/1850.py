def get_gcd(a, b):
    c = 0
    while b != 0:
        c = a % b
        a = b
        b = c

    return a


A, B = input().split(" ")
A = int(A)
B = int(B)

gcd = get_gcd(A, B)

num_str = "1" * gcd

print(num_str)
