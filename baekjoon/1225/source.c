#include <stdio.h>

int main(void){
    char a[10010], b[10010];
    long long sum = 0;
    scanf("%s", a);
    scanf("%s", b);
    for(int i=0;a[i]!=0;i++){
        for(int j=0;b[j]!=0;j++){
            sum += (a[i]-'0') * (b[j]-'0');
        }
    }
    printf("%lld", sum);
    return 0;
}
