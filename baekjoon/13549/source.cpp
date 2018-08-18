#include <stdio.h>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int main(void){
    int n, k, cost, cur;
    bool visited[100010] = {false};
    priority_queue<pair<int, int>> pq;
    scanf("%d %d", &n, &k);
    pq.emplace(0, n);
    visited[n] = true;
    while(!pq.empty()){
        tie(cost, cur) = pq.top();
        pq.pop();
        if(cur==k){
            printf("%d", -cost);
            break;
        }
        visited[cur] = true;
        if(cur-1>=0 && !visited[cur-1]) pq.emplace(cost-1, cur-1);
        if(cur+1<=100000 && !visited[cur+1]) pq.emplace(cost-1, cur+1);
        if(cur*2<=100000 && !visited[cur*2]) pq.emplace(cost, cur*2);
    }
    return 0;
}
