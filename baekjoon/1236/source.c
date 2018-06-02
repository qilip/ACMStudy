#include <stdio.h>

int main(void){
    int n, m, nn[60] = {0}, mm[60] = {0}, ncnt = 0, mcnt = 0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char tmp;
            scanf(" %c", &tmp);
            if(tmp=='X') { nn[i] = 1; mm[j] = 1; }
        }
    }
    for(int i=0;i<n;i++) ncnt += !nn[i];
    for(int j=0;j<m;j++) mcnt += !mm[j];
    printf("%d", ncnt<mcnt ? mcnt : ncnt);
    return 0;
}
