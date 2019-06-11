#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main(void){
    int n, l, k;
    vector<pair<int, int>> v;
    vector<int> nv;
    scanf("%d %d %d", &n, &l, &k);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(b, a); //어려운거 앞
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int ans = 0;
    for(auto cur = v.begin(); cur != v.end(); cur++){
        if(!k) break;
        if(cur->first <= l){
            ans += 140;
            cur = v.erase(cur);
            cur--;
            k--;
        }else{
            nv.push_back(cur->second);
        }
    }
    for(auto cur = nv.begin(); cur != nv.end(); cur++){
        if(!k) break;
        if(*cur <= l){
            ans += 100;
            k--;
        }
    }
    printf("%d", ans);
    return 0;
}
