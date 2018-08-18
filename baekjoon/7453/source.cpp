#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long cnt;
int a[4010], b[4010], c[4010], d[4010];
int cd[1600'0010], cptr;

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cd[cptr++] = c[i]+d[j];
        }
    }
    sort(cd, cd+cptr);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt += upper_bound(cd, cd+cptr, (a[i]+b[j])*-1) - lower_bound(cd, cd+cptr, (a[i]+b[j])*-1);
        }
    }
    printf("%lld", cnt);
    return 0;
}
