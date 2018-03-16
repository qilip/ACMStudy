#include <stdio.h>

int in[100010], dd[100010];

int main(void){
    int n, mx;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &in[i]);
    mx = dd[0] = in[0];
    for(int i=1;i<n;i++){
        if(dd[i-1]+in[i]>=in[i]) dd[i] = dd[i-1]+in[i];
        else dd[i] = in[i];
        if(dd[i]>mx) mx = dd[i];
    }
    printf("%d", mx);
}
