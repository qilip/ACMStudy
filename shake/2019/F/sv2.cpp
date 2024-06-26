#include <stdio.h>
// #include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

typedef long long ll;

int main(void){
    int n, w;
    vector<ll> v3;
    vector<ll> v5;
    scanf("%d %d", &n, &w);
    for(int i=0;i<n;i++){
        int t;
        ll s;
        scanf("%d %lld", &t, &s);
        if(t==3){
            v3.push_back(s);
        }else{
            v5.push_back(s);
        }
    }
    sort(v3.begin(), v3.end(), greater<ll>());
    sort(v5.begin(), v5.end(), greater<ll>());
    stack<ll> i5;
    ll ans = 0;
    ll cur = 0;
    for(auto c5 : v5){
        if(w>=5){
            w -= 5;
            cur += c5;
            i5.push(c5);
        }else{
            break;
        }
    }
    ans = ans > cur ? ans : cur;
    for(auto c3 : v3){
        if(w<3){
            if(i5.empty()) break;
            w += 5;
            ans = ans > cur ? ans : cur;
            cur -= i5.top();
            i5.pop();
        }
        if(w>=3){
            w -= 3;
            cur += c3;
        }
    }
    ans = ans > cur ? ans : cur;
    printf("%lld", ans > cur ? ans : cur);
    return 0;
}
