import sys

input = sys.stdin.readline

n, m, b = map(int, input().split())
nm = [list(map(int, input().split())) for _ in range(n)]
nn = [y for x in nm for y in x]
fn = [0] * 257
ans = 99999999
ansi = -1
for i in nn:
    fn[i]+=1
mtn = [0] * 257
mcnt = [0] * 257
ntm = [0] * 257
ncnt = [0] * 257
nfn = [0] * 257
mfn = [0] * 257
nfn[0] = fn[0]
mfn[256] = fn[256]
for i in range(1, 257):
    nfn[i] = nfn[i-1] + fn[i]
    ntm[i] = ntm[i-1] + nfn[i-1]
    ncnt[i] = ncnt[i-1] + nfn[i-1]
for i in range(255, -1, -1):
    mfn[i] = mfn[i+1] + fn[i]
    mtn[i] = mtn[i+1] + mfn[i+1] * 2
    mcnt[i] = mcnt[i+1] + mfn[i+1]

for i in range(0, 257):
    if ans >= ntm[i]+mtn[i] and ncnt[i]-mcnt[i]<=b:
        ans = ntm[i]+mtn[i]
        ansi = i
print(ans, ansi)
