#include <cstdio>
#include <algorithm>

using namespace std;

struct edge {
    int a, b, cost;
    bool operator < (const edge &O) const {
        return cost < O.cost;
    }
};

edge inp[100005];
int p[10004];

int find(int cur){
    if(cur==p[cur]) return cur;
    return p[cur] = find(p[cur]);
}

bool merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b) return 0;
    p[b] = a;
    return 1;
}


int main(void){
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i=1;i<=V;i++){
        p[i]=i;
    }
    for(int i=0;i<E;i++){
        scanf("%d %d %d", &inp[i].a, &inp[i].b, &inp[i].cost);
    }
    sort(inp, inp+E);
    int ans = 0, cnt;
    for(int i=0;i<E;i++){
        if(merge(inp[i].a, inp[i].b)){
            ans+=inp[i].cost;
            cnt++;
        }
        if(cnt==V-1) break;
    }
    printf("%d", ans);
    return 0;
}
