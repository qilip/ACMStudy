#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int main(void){
    int n, m, nn[10010] = {0};
    vector<pair<int, int>> out[10010];
    priority_queue<tuple<int, int, int, int>> pq;
    scanf("%d %d", &n, &m);
    while(m--){
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        nn[b]++;
        out[a].emplace_back(b, t);
    }
    int s, d;
    scanf("%d %d", &s, &d);
    pq.emplace(0, 0, s, 0);
    while(get<0>(pq.top())==0){
        int ing, now, cost, cnt;
        tie(ing, cost, now, cnt) = pq.top();
        printf("%d %d %d %d\n", ing, now, cost, cnt);
        pq.pop();
        if(now==d){
            printf("%d\n%d", cost, cnt);
            break;
        }
        for(auto i : out[now]){
            nn[i.first]--;
            pq.emplace(-nn[i.first], cost+i.second, i.first, cnt+1);
        }
    }
    return 0;
}
