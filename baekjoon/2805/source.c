#include <stdio.h>

int n, m, max;
int tree[1000010];

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &tree[i]);
        if(tree[i]>max) max = tree[i];
    }
    int high = max, low = 0, mid, ans = 0;
    while(high>=low){
        mid = (high+low)/2;
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += mid<tree[i] ? tree[i]-mid : 0;
        }
        if(sum >= m){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    printf("%d", ans);
    return 0;
}
