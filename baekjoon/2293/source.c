#include <stdio.h>

int main(void){
    int n, k, nn[110], c[10010] = {0};
    c[0] = 1;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<k;i++){
            if(i+nn[j]>k) continue;
            c[i+nn[j]] += c[i];
        }
    }
    printf("%d", c[k]);
    return 0;
}
