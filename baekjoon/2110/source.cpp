#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n, c, x[200010], max = 0;
    scanf("%d %d", &n, &c);
    for(int i=0;i<n;i++){
        scanf("%d", &x[i]);
        if(x[i]>max) max = x[i];
    }
    sort(x, x+n);
    int l = 1, r = max-1, mid, ans = 1;
    while(l<=r){
        mid = (l+r)/2;
        int cha = 0, cnt = 1;
        for(int i=1;i<n;i++){
            cha += x[i]-x[i-1];
            if(cha >= mid){
                cnt++;
                cha = 0;
            }
        }
        if(cnt>=c){
            l = mid+1;
            ans = mid;
        }else{
            r = mid-1;
        }
    }
    printf("%d", ans);
    return 0;
}
