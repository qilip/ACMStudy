#include <stdio.h>

int main(void) {
    int n;
    int t[20], p[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }

    int dp[99] = { 0 };
    for (int i = 0; i < n; i++) {
        int bef_max = 0;
        for (int j = 0; j < i; j++) {
            if (bef_max < dp[j]) bef_max = dp[j];
        }
        if (dp[i + t[i] - 1] < p[i] + bef_max)
            dp[i + t[i] - 1] = p[i] + bef_max;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < dp[i]) max = dp[i];
    }
    printf("%d\n", max);

    return 0;
}
