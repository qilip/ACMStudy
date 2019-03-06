#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    int nn[1010];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    int mm[1010];
    int mcnt = 0;
    int sum = 0;
    mm[mcnt++] = 0;
    for(int i=1;i<n-1;i++){
        if(nn[mm[mcnt-1]] <= nn[i] && nn[i] <= nn[i+1]) continue;
        if(nn[mm[mcnt-1]] >= nn[i] && nn[i] >= nn[i+1]) continue;
        mm[mcnt++] = i;
        sum += abs(nn[mm[mcnt-2]] - nn[i]);
    }
    mm[mcnt++] = n-1;
    sum += abs(nn[mm[mcnt-2]] - nn[n-1]);
    int bef = -1;
    for(int i=1;i<mcnt-1;i++){
        if(abs(nn[mm[i]-1]-nn[mm[i]]) < abs(nn[mm[i]]-nn[mm[i]+1])){
            if(bef == mm[i]-1) continue;
            sum -= abs(nn[mm[i]-1]-nn[mm[i]]);
        }else{
            bef = mm[i];
            sum -= abs(nn[mm[i]]-nn[mm[i]+1]);
        }
    }
    printf("%d", sum);
    return 0;
}
