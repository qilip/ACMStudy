#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    int tmp = a;
    int new = 0;
    int cnt = 0;
    if(a==0) {
        printf("1");
        return 0;
    }
    while(a!=new) {
        int q = tmp/10;
        int w = tmp%10;
        tmp = q + w;
        tmp = (w*10)+(tmp%10);
        new = tmp;
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}
