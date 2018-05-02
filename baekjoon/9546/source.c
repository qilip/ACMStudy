#include <stdio.h>

int main(void){
    int k;
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        int n;
        scanf("%d", &n);
        printf("%d\n", (1<<n)-1);
    }
    return 0;
}
