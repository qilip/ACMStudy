#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
    int n;
    scanf("%d", &n);
    int nn[10'0010] = {0};
    int in[10'0010] = {0};
    for(int i=1;i<=n;i++){
        scanf("%d", &nn[i]);
        in[nn[i]]++;
    }
    vector<int> v;
    int cur = 1;
    int visited[10'0010] = {0};
    for(int i=1;i<=n;i++){
        if(visited[i] || in[i]) continue;
        if(cur != i) v.push_back(i);
        cur = i;
        while(!visited[cur]){
            visited[cur] = 1;
            cur = nn[cur];
            v.push_back(cur);
        }
    }
    for(int i=1;i<=n;i++){
        if(visited[i] || in[i]>1) continue;
        if(cur != i) v.push_back(i);
        cur = i;
        while(!visited[cur]){
            visited[cur] = 1;
            cur = nn[cur];
            v.push_back(cur);
        }
    }
    printf("%d\n", (int)v.size());
    for(int x : v) printf("%d ", x);
    return 0;
}
