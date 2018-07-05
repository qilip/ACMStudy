#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#define MAX 100000000

using namespace std;

int N, E;
vector<pair<int, int>> v[810];

int dijk(int src, int there){
    if(src==there) return 0;
    int dist[810];
    for(int i=0;i<=N;i++){
        dist[i] = MAX;
    }
    priority_queue<pair<int, int>> pq;
    for(int i=1;i<=N;i++){
        pq.emplace(-MAX, i);
    }
    pq.emplace(0, src);
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[now] < cost) continue;
        for(auto i : v[now]){
            int next = i.second;
            int next_cost = cost + i.first;
            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.emplace(-next_cost, next);
            }
        }
    }
    return dist[there];
}

int main(void){
    scanf("%d %d", &N, &E);
    for(int i=0;i<E;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].emplace_back(c, b);
        v[b].emplace_back(c, a);
    }
    int m_a, m_b;
    scanf("%d %d", &m_a, &m_b);
    int a_b = dijk(m_a, m_b);
    int src_a_b_dist = dijk(1, m_a) + a_b + dijk(m_b, N);
    int src_b_a_dist = dijk(1, m_b) + a_b + dijk(m_a, N);
    if(src_a_b_dist >= MAX || src_b_a_dist >= MAX ){
        printf("-1");
    }else{
        printf("%d", src_a_b_dist > src_b_a_dist ? src_b_a_dist : src_a_b_dist);
    }
    return 0;
}
