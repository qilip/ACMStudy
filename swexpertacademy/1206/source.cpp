#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int T = 10;
    for(int t=1;t<=T;t++){
        int n, nn[1010], ans = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &nn[i]);
        }
        for(int i=2;i<n-2;i++){
            int gj = nn[i] - max(max(nn[i-1], nn[i-2]), max(nn[i+1], nn[i+2]));
            if(gj>0) ans += gj;
        }
        printf("#%d %d\n", t, ans);
    }
    return 0;
}
