#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int st = n / 5;
    while(st >= 0) {
        int r = n - st * 5;
        if (r % 3 == 0) {
            printf("%d", st + r / 3);
            return 0;
        }
        st--;
    }
    printf("-1");
    return 0;
}
