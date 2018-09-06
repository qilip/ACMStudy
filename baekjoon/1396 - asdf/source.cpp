#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

struct edge{
    int st, ed, cost;
    bool operator< (const edge &o) const{
        return cost < o.cost;
    }
};

int n, m, q;
vector<edge> ve;
vector<pair<int, int>> qr;
vector<tuple<int, int, int>> tp;
int par[100'010];
int siz[100'010];

int find(int a){

}

void uni(int a, int b){

}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        ve.emplace_back(a, b, c);
    }
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        qr.emplace_back(x, y);
        tp.emplace_back(1, 1'000'000, i);
    }
    sort(ve.begin(), ve.end());
    for(int k=1'000'000;k>0;k/=2){
        for(int i=0;i<=n;i++) par[i] = i, siz[i] = 1;
        
    }

    return 0;
}
