#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    setbuf(stdout, NULL);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n, k, max = 0, nn[200010];
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;i++){
            scanf("%d", &nn[i]);
        }
        sort(nn, nn+n);
        for(int i=0;i<n;i++){
            int tmp = upper_bound(nn, nn+n, nn[i]+k) - nn - i;
            if(max<tmp) max = tmp;
        }
        printf("Case #%d\n", t);
        printf("%d\n", max);
    }
    return 0;
}
