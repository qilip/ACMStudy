#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    int n, t;
    int add[10'0010] = {0};
    int sub[10'0010] = {0};
    scanf("%d %d", &n, &t);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d", &k);
        for(int j=0;j<k;j++){
            int a, b;
            scanf("%d %d", &a, &b);
            add[a]++;
            sub[b]++;
        }
    }
    int stu[10'0010] = {0};
    ll ans = 0;
    pair<int, int> ans_time = {0, 0};
    ll cur = 0;
    stu[0] = add[0] - sub[0];
    for(int i=1;i<=100000;i++){
        stu[i] = stu[i-1] + add[i] - sub[i];
    }
    for(int i=0;i<t;i++) cur += stu[i];
    ans = cur;
    ans_time = {0, t};
    for(int i=t;i<=100000;i++){
        cur += stu[i] - stu[i-t];
        if(cur > ans){
            ans = cur;
            ans_time = {i-t+1, i+1};
        }
    }
    printf("%d %d", ans_time.first, ans_time.second);
    return 0;
}
