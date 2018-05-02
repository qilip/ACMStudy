#include <stdio.h>

int main(void) {
    int T, H, W;
    char HW[11][11];
    scanf("%d", &T);
    for(int m=0;m<T;m++) {
        scanf("%d %d", &H, &W);
        for (int i=0;i<H;i++) scanf("%s", HW[i]);
        for (int i=0;i<H;i++) {
            for (int j=W-1;j>=0;j--) {
                printf("%c", HW[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
