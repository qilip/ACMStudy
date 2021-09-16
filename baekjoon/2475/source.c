#include <stdio.h>

int main(void){
    int a, ans = 0;
    for(int i=0;i<5;i++){
        scanf("%d", &a);
        ans += a*a;
    }
    printf("%d", ans%10);
    return 0;
}
