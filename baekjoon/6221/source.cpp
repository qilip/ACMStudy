#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int n;
pair<int, int> p[21];
int ans;

void func(int depth, int height, int bef, int bes){
    if(depth==n){
        if(ans < height) ans = height;
        return;
    }
    func(depth+1, height, bef, bes);
    if(p[depth].first < bef && p[depth].second < bes){
        func(depth+1, height+1, p[depth].first, p[depth].second);
    }
}

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p, p+n, greater<pair<int, int>>());
    func(0, 0, 9'9999'9999, 9'9999'9999);
    printf("%d", ans);
    return 0;
}
