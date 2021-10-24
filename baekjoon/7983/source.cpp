#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(-b, a);
    }
    sort(v.begin(), v.end());
    int cur = 1e9+1;
    for(auto c : v){
        int b = -c.first;
        int a = c.second;
        if(cur > b) cur = b;
        cur -= a;
    }
    printf("%d\n", cur);
    return 0;
}
