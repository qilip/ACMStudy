#include <stdio.h>

int n, nn[1000010];

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        long long ans = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &nn[i]);
        }
        int max = 0;
        for(int i=n-1;i>=0;i--){
            if(max<nn[i]) max = nn[i];
            else ans += max-nn[i];
        }
        printf("#%d %lld\n", t, ans);
    }
    return 0;
}
