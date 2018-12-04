#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k, w, cost[1010], add[1010] = {0}, in[1010] = {0};
        vector<int> v[1010];
        queue<int> q;
        scanf("%d %d", &n, &k);
        for(int i=1;i<=n;i++){
            scanf("%d", &cost[i]);
        }
        for(int i=0;i<k;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            in[b]++;
            v[a].push_back(b);
        }
        scanf("%d", &w);
        for(int i=1;i<=n;i++){
            if(!in[i]) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cost[cur] += add[cur];
            for(int i : v[cur]){
                in[i]--;
                if(add[i] < cost[cur]) add[i] = cost[cur];
                if(!in[i]) q.push(i);
            }
        }
        printf("%d\n", cost[w]);
    }
    return 0;
}
