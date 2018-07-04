#include <stdio.h>
#include <stdlib.h>
#include <utility>

struct xy{
    int x;
    int y;
};

int n, nu[100010], max;
xy ii[100010];

int main(void){
    scanf("%d", &n);
    scanf("%d %d", &ii[0].x, &ii[0].y);
    for(int i=1;i<n;i++){
        scanf("%d %d", &ii[i].x, &ii[i].y);
        nu[i] = nu[i-1] + abs(ii[i].x-ii[i-1].x) + abs(ii[i].y-ii[i-1].y);
    }
    for(int i=1;i<n-1;i++){
        int now = nu[i+1] - nu[i-1];
        int may = abs(ii[i+1].x - ii[i-1].x) + abs(ii[i+1].y - ii[i-1].y);
        if(max < now-may) max = now-may;
    }
    printf("%d", nu[n-1] - max);
    return 0;
}
