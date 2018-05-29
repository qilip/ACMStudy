#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int nn[1020];
    for(int i=0;i<n;i++){
        scanf(" %d", &nn[i]);
    }
    int t;
    scanf("%d", &t);
    int shotbuf = 1000000000, shottime = 1000000000;
    for(int i=1;i<=1000;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            cnt += (nn[j]/i*t+nn[j]%i)*i;
        }
        if(cnt<shottime){
            shotbuf = i;
            shottime = cnt;
        }
    }
    printf("%d %d", shottime, shotbuf);
}
