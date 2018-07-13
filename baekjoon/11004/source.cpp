#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, nn[5000010];

int main(void){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    nth_element(nn, nn+k-1, nn+n);
    printf("%d", nn[k-1]);
    return 0;
}
