#include <algorithm>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
    int n, m;
    int nm[10][10] = {};
    vector<pair<int, int>> start_point;
    int cnt_zro = 0;
    for (int i = 0; i < 100; i++)
        *(*nm + i) = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &nm[i][j]);
            if (nm[i][j] == 2) start_point.emplace_back(i, j);
            if (nm[i][j] == 0) cnt_zro++;
        }
    }

    int x[] = { 1, 0, -1, 0 };
    int y[] = { 0, 1, 0, -1 };
    int min_two = 9999;

    for (int i = 0; i < n * m; i++) {
        if (nm[i / m + 1][i % m + 1]) continue;
        for (int j = i + 1; j < n * m; j++) {
            if (nm[j / m + 1][j % m + 1]) continue;
            for (int k = j + 1; k < n * m; k++) {
                if (nm[k / m + 1][k % m + 1]) continue;

                queue<pair<int, int>> q;
                int visited[10][10] = {};
                visited[i / m + 1][i % m + 1] = visited[j / m + 1][j % m + 1] = visited[k / m + 1][k % m + 1] = 1;
                for (auto v : start_point)
                    q.push(v);

                int cnt_two = 3;

                while (!q.empty()) {
                    auto [curx, cury] = q.front();
                    q.pop();
                    for (int a = 0; a < 4; a++) {
                        int nxtx = curx + x[a];
                        int nxty = cury + y[a];
                        if (!nm[nxtx][nxty] && !visited[nxtx][nxty]) {
                            visited[nxtx][nxty] = 1;
                            cnt_two++;
                            q.emplace(nxtx, nxty);
                        }
                    }
                }
                if (min_two > cnt_two) min_two = cnt_two;
            }
        }
    }

    printf("%d\n", cnt_zro - min_two);
    return 0;
}
