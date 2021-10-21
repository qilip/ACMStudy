import sys

input = sys.stdin.readline

n = int(input())

arr = [list(map(int, input().split())) for _ in range(n*n)]

room = [[0] * n for _ in range(n)]

for stu in arr:
    cur = stu[0]
    best_score = [0, 0, -9999, -9999]
    best_xy = [0, 0]
    for x in range(n):
        for y in range(n):
            if room[x][y]: continue
            score = [0, 0, -9999, -9999]
            for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if not (0 <= nx < n and 0 <= ny < n): continue
                for i in range(1, 5):
                    score[0] += 1 if room[nx][ny] == stu[i] else 0
                score[1] += 1 if not room[nx][ny] else 0
            if -score[2] >= x or (-score[2] == x and -score[3] > y):
                score[2] = -x
                score[3] = -y
            if(score > best_score):
                best_score = score
                best_xy = [x, y]
    room[best_xy[0]][best_xy[1]] = cur
ans = 0
arr.sort(key=lambda x: x[0])
for x in range(n):
    for y in range(n):
        cnt = 0
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if not (0 <= nx < n and 0 <= ny < n): continue
            if room[nx][ny] in [arr[room[x][y]-1][1], arr[room[x][y]-1][2], arr[room[x][y]-1][3], arr[room[x][y]-1][4]]:
                cnt += 1
        ans += 10 ** (cnt-1) if cnt > 0 else 0
print(ans)
