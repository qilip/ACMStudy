#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n, m, nn[110];
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++) nn[i] = i;
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        swap(nn[a], nn[b]);
    }
    for(int i=1;i<=n;i++) printf("%d ", nn[i]);
    return 0;
}
