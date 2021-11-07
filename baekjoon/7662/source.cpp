#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        priority_queue<ll, vector<ll>, less<ll>> lq;
        priority_queue<ll, vector<ll>, greater<ll>> rq;
        unordered_map<ll, int> mm;
        int cnt = 0;
        while(n--){
            char a;
            ll b;
            scanf(" %c %lld", &a, &b);
            if(a == 'I'){
                cnt++;
                lq.push(b);
                rq.push(b);
                mm[b] += 1;
            }else{
                if(!cnt) continue;
                cnt--;
                if(b==1){
                    while(!mm[lq.top()]) lq.pop();
                    mm[lq.top()]--;
                    lq.pop();
                }
                else{
                    while(!mm[rq.top()]) rq.pop();
                    mm[rq.top()]--;
                    rq.pop();
                }
            }
        }
        if(!cnt) printf("EMPTY\n");
        else{
            while(!mm[lq.top()]) lq.pop();
            while(!mm[rq.top()]) rq.pop();
            printf("%lld %lld\n", lq.top(), rq.top());
        }
    }
    return 0;
}
