#include <stdio.h>

int n, nn[2000010];

int main(void){
    scanf("%d", &n);
    while(n--){
        int tmp;
        scanf("%d", &tmp);
        nn[tmp+1000000]++;
    }
    for(int i=0;i<2000010;i++)
        if(nn[i]) printf("%d\n", i-1000000);
    return 0;
}
