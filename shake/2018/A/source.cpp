#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

int main(void){
    int n, cnt = 0;
    pair<int, int> nn[100];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        nn[i] = make_pair(-a, b);
    }
    sort(nn, nn+n);
    int as = nn[4].first;
    for(int i=5;i<n;i++){
        if(as == nn[i].first) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
