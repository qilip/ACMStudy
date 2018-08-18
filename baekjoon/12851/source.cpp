#include <stdio.h>
#include <queue>
#include <tuple>

using namespace std;

int main(void){
    int n, k, tim = 0, cur;
    bool visited[100010] = {false};
    priority_queue<pair<int, int>> pq;
    scanf("%d %d", &n, &k);
    pq.emplace(0, n);
    visited[n] = true;
    while(!pq.empty()){
        tie(tim, cur) = pq.top();
        pq.pop();
        visited[cur] = true;
        if(cur==k) break;
        if(cur-1>=0 && !visited[cur-1]) { pq.emplace(tim-1, cur-1); }
        if(cur+1<=100000 && !visited[cur+1]) { pq.emplace(tim-1, cur+1); }
        if(cur*2<=100000 && !visited[cur*2]) { pq.emplace(tim-1, cur*2); }
    }
    int cnt = 1;
    while(!pq.empty()){
        cur = pq.top().second;
        pq.pop();
        if(cur!=k) break;
        cnt++;
    }
    printf("%d\n%d", tim*-1, cnt);
    return 0;
}
