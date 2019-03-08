#include <stdio.h>
#include <string.h>

int main(void){
    int c, n;
    int cc[1010];
    memset(cc, 0x3f, sizeof(cc));
    cc[0] = 0;
    scanf("%d %d", &c, &n);
    for(int i=0;i<n;i++){
        int cur;
        scanf("%d", &cur);
        int p = cur;
        while(p<=1000){
            cc[p] = cc[p] > cc[p-cur]+1 ? cc[p-cur]+1 : cc[p];
            p++;
        }
    }
    printf("%d", cc[c]);
    return 0;
}
