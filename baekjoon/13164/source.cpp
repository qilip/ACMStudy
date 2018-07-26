#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int n, k, cut[300010], ans;

int main(void){
    scanf("%d %d", &n, &k);
    int tmp;
    scanf("%d", &tmp);
    for(int i=1;i<n;i++){
        int cur;
        scanf("%d", &cur);
        cut[i-1] = cur-tmp;
        tmp = cur;
    }
    sort(cut, cut+n-1, greater<int>());
    for(int i=k-1;i<n-1;i++){
        ans += cut[i];
    }
    printf("%d", ans);
    return 0;
}
