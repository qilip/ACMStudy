#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;
typedef unsigned int usint;
typedef long long ll;

vector<int> graph[100010];
usint power[100010];
usint df[100010];
int maxdep;
void dfs(int cur, int dep, int start){
    if(dep > maxdep) maxdep = dep;
    df[dep] += power[cur];
    for(int nxt : graph[cur]){
        if(nxt == start) continue;
        dfs(nxt, dep+1, cur);
    }
}

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i=0;i<n-1;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        scanf("%u", &power[i]);
    }
    for(int p=0;p<q;p++){
        int sp;
        scanf("%d", &sp);

        //jisu's
        usint jpower = 0;
        usint jpoint = 0;
        for(int nxt : graph[sp]){
            usint jtmp = 0;
            for(int i=0;i<=n;i++)
                df[i] = 0;
            maxdep = 0;
            dfs(nxt, 0, sp);
            for(int i=0;i<=maxdep;i++){
                jtmp += df[i] * (maxdep-i+1);
            }
            if(jpower < jtmp){
                jpower = jtmp;
                jpoint = nxt;
            }
        }

        //sangmin's
        usint spower = 0;
        for(int i=0;i<=n;i++)
            df[i] = 0;
        maxdep = 0;
        dfs(sp, 0, jpoint);
        for(int i=0;i<=maxdep;i++){
            spower += df[i] * (maxdep-i+1);
        }
        printf("%u ", spower);
        printf("%lld\n", (ll)jpower-(ll)spower);
    }
    return 0;
}
