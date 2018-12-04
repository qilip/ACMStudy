#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int main(void){
    int n, cost[510], add[510] = {0}, in[510] = {0};
    vector<int> v[510];
    queue<pair<int, int>> q;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int req;
        scanf("%d", &cost[i]);
        scanf("%d", &req);
        while(req!=-1){
            v[req].push_back(i);
            in[i]++;
            scanf("%d", &req);
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0) q.emplace(0, i);
    }
    while(!q.empty()){
        int cur = q.front().second;
        q.pop();
        cost[cur] += add[cur];
        for(int i : v[cur]){
            in[i]--;
            if(add[i] < cost[cur]) add[i] = cost[cur];
            if(in[i]==0){
                q.emplace(0, i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n", cost[i]);
    }
    return 0;
}
