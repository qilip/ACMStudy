#include <stdio.h>

int main(void){
    int n, max = 0;
    char s[55][55];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", s[i]);
    }
    for(int i=0;i<n;i++){
        int flg[55] = {0};
        for(int j=0;j<n;j++){
            if(s[i][j]=='Y'){
                flg[j] = 1;
                for(int k=0;k<n;k++)
                    if(s[j][k]=='Y') flg[k] = 1;
            }
        }
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(flg[j]) cnt++;
        }
        if(max < cnt) max = cnt;
    }
    printf("%d", max);
    return 0;
}
