N = int(input())
S = str(input())
D, M = map(int, input().split())

HYU = {'H', 'Y', 'U'}
HYU_cnt = dict()

for e in HYU:
    HYU_cnt[e] = 0

ans = 0

i = 0
while i < len(S):
    if S[i] in HYU:
        HYU_cnt[S[i]] += 1
        i += 1
        continue
    j = 1
    while i + j < len(S) and S[i + j] not in HYU:
        j += 1
    if j > 1:
        if M + D < D * j:
            ans += M + D
        else:
            ans += D * j
    else:
        ans += D
    i += j


if ans == 0:
    print("Nalmeok")
else:
    print(ans)
    
ans2 = min(HYU_cnt.values())

if ans2 == 0:
    print("I love HanYang University")
else:
    print(ans2)