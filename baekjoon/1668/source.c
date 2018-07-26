#include <stdio.h>

int main(void){
    int n, nn[60];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    int cnt = 0, m = 0;
    for(int i=0;i<n;i++){
        if(nn[i]>m){
            cnt++;
            m = nn[i];
        }
    }
    printf("%d\n", cnt);
    cnt = 0, m = 0;
    for(int i=n-1;i>=0;i--){
        if(nn[i]>m){
            cnt++;
            m = nn[i];
        }
    }
    printf("%d\n", cnt);
    return 0;
}
