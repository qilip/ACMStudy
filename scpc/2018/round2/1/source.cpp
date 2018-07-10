#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    setbuf(stdout, NULL);
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n, nn[200010], ori[200010], cnt = 0, max = 0;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &nn[i]);
            ori[i] = nn[i];
        }
        sort(nn, nn+n);
        for(int i=0;i<n;i++){
            if(ori[i]==nn[i] && max < nn[i]){
                cnt++;
            }
            if(ori[i]>max) max = ori[i];
        }
        printf("Case #%d\n", t);
        printf("%d\n", cnt);
    }
    return 0;
}
