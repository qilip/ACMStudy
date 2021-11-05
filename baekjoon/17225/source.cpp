#include <bits/stdc++.h>

using namespace std;

int main(void){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    priority_queue<pair<int, int>> pq;
    int st = 0, jt = 0;
    for(int i=0;i<n;i++){
        int t, m;
        char c;
        scanf("%d %c %d", &t, &c, &m);
        for(int j=0;j<m;j++){
            if(c=='B') st = st > t ? st : t;
            else jt = jt > t ? jt : t;
            int ct = c=='B' ? st : jt;
            if(c=='B') st += a;
            else jt += b;
            pq.emplace(-ct, c=='B' ? 1 : 0);
        }
    }
    int cnt = 1;
    vector<int> sang, jisu;
    while(!pq.empty()){
        auto [t, c] = pq.top();
        pq.pop();
        if(c) sang.push_back(cnt);
        else jisu.push_back(cnt);
        cnt++;
    }
    printf("%ld\n", sang.size());
    for(int c : sang) printf("%d ", c);
    printf("\n%ld\n", jisu.size());
    for(int c : jisu) printf("%d ", c);
    return 0;
}
