#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100010];
int incnt[100010] = {0};
int tncnt[100010] = {0};
bool can[100010] = {false};

int main(void){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[b].push_back(a);
        incnt[a]++;
    }

    for(int i=0;i<q;i++){
        int w, x, y;
        scanf("%d %d %d", &w, &x, &y);
        if(w==1){

            //
            for(int i=1;i<=n;i++){
                tncnt[i] = incnt[i];
                can[i] = false;
            }
            queue<int> qu;
            for(int i=x;i<=y;i++){
                if(!incnt[i]){
                    qu.push(i);
                }
            }
            while(!qu.empty()){
                int cur = qu.front();
                qu.pop();
                if(cur<x || y<cur) continue;
                can[cur] = true;
                for(auto nxt : graph[cur]){
                    tncnt[nxt]--;
                    if(!tncnt[nxt]) qu.push(nxt);
                }
            }
            //

            bool flg = 0;
            for(int j=x;j<=y;j++){
                if(!can[j]) flg = 1;
            }
            if(flg) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}
