#include <stdio.h>

int main(void){
    int n, b, w;
    int nw[300010], ptr = 0;
    char nn[300010];
    scanf("%d %d %d", &n, &b, &w);
    scanf("%s", nn+1);
    nw[ptr++] = 0;
    for(int i=1;i<=n;i++){
        if(nn[i]=='B'){
            nw[ptr++] = i;
        }
    }
    nw[ptr++] = n+1;
    int maxs = 0;
    for(int i=b+1;i<ptr;i++){
        int t = nw[i] - nw[i-b-1] - 1;
        if(maxs < t) maxs = t;
    }
    if(ptr-2 <= b){
        maxs = n;
    }
    if(maxs - b < w) printf("0");
    else printf("%d", maxs);
    return 0;
}
