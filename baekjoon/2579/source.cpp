#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[310] = { 0 };
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int score[310][2] = { 0 };
    score[0][0] = arr[0];
    score[1][0] = arr[1];
    score[1][1] = arr[0] + arr[1];
    for (int i = 2; i < n; i++){
        score[i][0] = max(score[i-2][0] + arr[i], score[i-2][1] + arr[i]);
        score[i][1] = score[i-1][0] + arr[i];
    }
    printf("%d", max(score[n - 1][0], score[n - 1][1]));
    return 0;
}
