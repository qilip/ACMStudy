#include <stdio.h>

int main(void){
    int n, m, nn[100010], sum = 0, maxx = 0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
        sum += nn[i];
        if(nn[i]>maxx) maxx = nn[i];
    }
    int min = maxx, max = sum, mid, ans = -1;
    while(min<=max){
        mid = (min+max)/2;
        int mon = 0, cnt = 0;
        for(int i=0;i<n;i++){
            if(mon>=nn[i]){
                mon -= nn[i];
            }else{
                cnt++;
                mon = mid - nn[i];
            }
        }
        if(cnt>m){
            min = mid+1;
        }else{
            max = mid-1;
            ans = mid;
        }
    }
    printf("%d", ans);
    return 0;
}
