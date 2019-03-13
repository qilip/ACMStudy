#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

struct cmp{
    bool operator()(const pair<int, int> &o, const int &key){
        return o.first < key;
    }
    bool operator()(const int &key, const pair<int, int> &o){
        return key < o.first;
    }
};

int main(void){
    int n, t;
    pair<int, int> nn[25010];
    int maxx[25010] = {0};
    scanf("%d %d", &n, &t);
    for(int i=0;i<n;i++){
        scanf("%d %d", &nn[i].first, &nn[i].second);
    }
    sort(nn, nn+n);
    maxx[0] = nn[0].second;
    for(int i=1;i<n;i++){
        maxx[i] = maxx[i-1] > nn[i].second ? maxx[i-1] : nn[i].second;
    }
    if(nn[0].first != 1){
        printf("-1");
        return 0;
    }
    int ptr = 1;
    int ans = 0;
    while(ptr-1<t){
        int p = upper_bound(nn, nn+n, ptr, cmp())-nn;
        if(p>n || ptr-1 == maxx[p-1]){
            ans = -1;
            break;
        }
        ptr = maxx[p-1] + 1;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
