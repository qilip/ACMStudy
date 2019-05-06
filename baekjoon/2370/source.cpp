#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    vector<pair<int, int> > v;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int l, r;
        scanf("%d %d", &l, &r);
        v.emplace_back(l, i);
        v.emplace_back(r+1, i); // 끝이 시작보다 뒤에 있어야함
    }
    sort(v.begin(), v.end());
    bool chk[10010] = {false};
    bool top[10010] = {false};
    priority_queue<int> pq;
    int cnt = 0, nxt = -1;
    for(auto i=v.begin();i!=v.end();i++){
        if(i+1==v.end()) nxt = -1;
        else nxt = (i+1)->first;
        int idx = i->first;
        int dep = i->second;
        if(!chk[dep]){
            chk[dep] = true;
            pq.push(dep);
        }else{
            chk[dep] = false;
        }
        while(!pq.empty() && !chk[pq.top()]) pq.pop();
        if(pq.empty()) continue;
        if(nxt != idx) top[pq.top()] = true;
    }
    for(int i=1;i<=10000;i++) if(top[i]) cnt++;
    printf("%d", cnt);
    return 0;
}
