#include <stdio.h>

int main(void) {
    int a, b, s=1;
    scanf("%d %d", &a, &b);
    for(int i=1;i<=b;i++) {
        s = s*(a-i+1)/i;
    }
    printf("%d",s);
}
