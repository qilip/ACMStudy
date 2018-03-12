#include <stdio.h>

int main(void){
    int n, m, na[100011] = {0}, ma[100011] = {0}, ptrn = 0, ptrm = 0, cnt=0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &na[i]);
    for(int i=0;i<m;i++) scanf("%d", &ma[i]);
    while( ( na[ptrn] != 0) || ( ma[ptrm] !=0) ){
        int tmpn = na[ptrn], tmpm=ma[ptrm];
        ptrn++; ptrm++;
        while(tmpn != tmpm) {
            if(tmpn>tmpm) {
                tmpm += ma[ptrm];
                ptrm++;
            }else if(tmpn<tmpm) {
                tmpn += na[ptrn];
                ptrn++;
            }
        }
        cnt++;
    }
    printf("%d", cnt);
}
