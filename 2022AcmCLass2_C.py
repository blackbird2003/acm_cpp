T = int(input())
for k in range(T):
    ans = 0
    n = int(input())
    pattern = input()
    for i in range(n):
        ans += input().split().count(pattern)
    print(ans) if ans > 0 else print("Do not find")
    print("")