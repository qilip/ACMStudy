#include <stdio.h>

int main(void){
    int n, sum = 0;
    char nn[110];
    scanf("%d", &n);
    scanf("%s", nn);
    for(int i=0;i<n;i++){
        sum += nn[i] - 'A' + 1;
    }
    printf("%d", sum);
    return 0;
}
