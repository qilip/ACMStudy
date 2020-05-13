#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n;
        int nn[110][110];
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d", &nn[i][j]);
            }
        }
        int k = 0, r = 0, c = 0;
        for(int i=0;i<n;i++){
            k += nn[i][i];
        }
        for(int i=0;i<n;i++){
            int cnt[110] = {0};
            int dup = 0;
            for(int j=0;j<n;j++){
                cnt[nn[i][j]]++;
                if(cnt[nn[i][j]]>1) dup = 1;
            }
            if(dup) r++;
        }
        for(int i=0;i<n;i++){
            int cnt[110] = {0};
            int dup = 0;
            for(int j=0;j<n;j++){
                cnt[nn[j][i]]++;
                if(cnt[nn[j][i]]>1) dup = 1;
            }
            if(dup) c++;
        }
        printf("Case #%d: %d %d %d\n", t, k, r, c);
    }
    return 0;
}
