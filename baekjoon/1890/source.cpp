#include <stdio.h>
#include <tuple>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef long long ll;

int main(void){
    int n;
    int nn[110][110];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &nn[i][j]);
        }
    }
    ll cnt[110][110] = {0};
    bool inq[110][110] = {false};
    cnt[0][0] = 1;
    int curx = 0, cury = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.emplace(curx, cury);
    inq[curx][cury] = true;
    while(!pq.empty()){
        tie(curx, cury) = pq.top();
        pq.pop();
        inq[curx][cury] = false;
        int plus = nn[curx][cury];
        if(!plus) continue;
        if(curx+plus<n){
            cnt[curx+plus][cury] += cnt[curx][cury];
            if(!inq[curx+plus][cury]) pq.emplace(curx+plus, cury);
            inq[curx+plus][cury] = true;
        }
        if(cury+plus<n){
            cnt[curx][cury+plus] += cnt[curx][cury];
            if(!inq[curx][cury+plus]) pq.emplace(curx, cury+plus);
            inq[curx][cury+plus] = true;
        }
    }
    printf("%lld", cnt[n-1][n-1]);
    return 0;
}
