#include <stdio.h>
#include <queue>

using namespace std;

typedef long long ll;

int main(void){
    int n, m;
    priority_queue<ll> pq;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d", &t);
        pq.push(-t);
    }
    for(int i=0;i<m;i++){
        ll a = -pq.top();
        pq.pop();
        ll b = -pq.top();
        pq.pop();
        ll s = a+b;
        pq.push(-s);
        pq.push(-s);
    }
    ll ans = 0;
    while(!pq.empty()){
        ans += -pq.top();
        pq.pop();
    }
    printf("%lld", ans);
    return 0;
}
