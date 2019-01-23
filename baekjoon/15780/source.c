#include <stdio.h>

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0;i<k;i++){
        int t;
        scanf("%d", &t);
        n -= (t+1)/2;
    }
    if(n<=0) printf("YES");
    else printf("NO");
    return 0;
}
