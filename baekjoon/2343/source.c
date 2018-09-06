#include <stdio.h>

int main(void){
    int n, m, les[100010], sum = 0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &les[i]);
        sum += les[i];
    }
    int min = 0, max = sum, mid, ans = -1;
    while(min<=max){
        mid = (min+max)/2;
        int cnt = 1, nu = 0, flg = 0;
        for(int i=0;i<n;i++){
            if(nu+les[i]<=mid){
                nu += les[i];
            }else{
                if(les[i]<= mid){
                    nu = les[i];
                    cnt++;
                }else{
                    flg = 1;
                    break;
                }
            }
        }
        if(flg || cnt>m){
            min = mid+1;
        }else{
            max = mid-1;
            ans = mid;
        }
    }
    printf("%d", ans);
    return 0;
}
