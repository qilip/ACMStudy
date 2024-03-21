#include <stdio.h>

using namespace std;

int x[4] = { 0, 0, 1, -1 };
int y[4] = { 1, -1, 0, 0 };
int m, n;
int mn[505][505];
int h[505][505];

int dfs(int cx, int cy) {
    if (cx == m - 1 && cy == n - 1) return 1;
    if (h[cx][cy] != -1) return h[cx][cy];
    h[cx][cy] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = cx + x[i];
        int ny = cy + y[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (mn[nx][ny] < mn[cx][cy]) h[cx][cy] += dfs(nx, ny);
    }
    return h[cx][cy];
}

int main(void) {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mn[i][j]);
            h[i][j] = -1;
        }
    }
    printf("%d\n", dfs(0, 0));
    return 0;
}
