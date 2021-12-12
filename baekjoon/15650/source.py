n, m = map(int, input().split())
arr = [0]
def run(cnt):
    if cnt == m:
        print(*arr[1:], sep=' ')
        return
    for i in range(arr[-1]+1, n+1):
        arr.append(i)
        run(cnt+1)
        arr.pop()
run(0)
