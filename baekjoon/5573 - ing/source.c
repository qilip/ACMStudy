#include <stdio.h>

int r[1010][1010] = {0};
int main(void) {
    int H, W, N, ptrh=1, ptrw=1;
    scanf("%d %d %d", &H, &W, &N);
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            scanf("%d", &r[i][j]);
        }
    }
    
    printf("%d %d", ptrh, ptrw);
    return 0;
}
