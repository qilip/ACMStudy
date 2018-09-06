#include <stdio.h>
#include <string.h>

int main(void){
    char n[100010];
    int bn[100010] = {0}, rn[100010] = {0};
    int max = 0, bst = 1, rst = 1, mst = 1, med = 1;
    scanf("%s", n+1);
    int len = strlen(n+1);
    for(int i=1;i<=len;i++){
        int cur = n[i]=='B' ? 1 : -1 ;
        int ncur = cur * -1;
        if(bn[i-1] + cur >= cur) bn[i] = bn[i-1] + cur;
        else bn[i] = cur, bst = i;
        if(max<bn[i]) max = bn[i], mst = bst, med = i;

        if(rn[i-1] + ncur >= ncur) rn[i] = rn[i-1] + ncur;
        else rn[i] = ncur, rst = i;
        if(max<rn[i]) max = rn[i], mst = rst, med = i;
    }
    printf("%d %d", mst, med);
    return 0;
}
