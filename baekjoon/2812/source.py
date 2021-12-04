import sys
input = sys.stdin.readline

n, k = map(int, input().split())
s = list(input().rstrip())

ans = list(s[0])
cnt = 0

for i in range(1, len(s)):
    if ans[-1] >= s[i]:
        ans.append(s[i])
    else:
        while ans and cnt<k and ans[-1] < s[i]:
            ans.pop()
            cnt+=1
        ans.append(s[i])
print(''.join(ans[:n-k]))
