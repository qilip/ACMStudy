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
    scanf("%d %d", &n, &t);
    for(int i=0;i<n;i++){
        scanf("%d %d", &nn[i].first, &nn[i].second);
    }
    sort(nn, nn+n);
    if(nn[0].first != 1){
        printf("-1");
        return 0;
    }
    int ptr = 1;
    int ans = 0;
    while(ptr<t){
        int p = upper_bound(nn, nn+n, ptr, cmp())-nn;
        if(p>n || ptr == nn[p-1].second){
            printf("%d %d %d %d\n", p, n, ptr, nn[p-1].second);
            ans = -1;
            break;
        }
        ptr = nn[p-1].second + 1;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
