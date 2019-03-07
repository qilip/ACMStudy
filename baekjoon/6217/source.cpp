#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(void){
    int N, I, H, R;
    scanf("%d %d %d %d", &N, &I, &H, &R);
    vector<int> nn[10010][2]; // 0: >= ; 1: > ;
    int hg[10010] = {0};
    int in[10010];
    queue<int> q;
    for(int i=0;i<R;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        nn[b][0].push_back(a);
        in[a]++;
        if(a<=b)
            for(int i=a+1;i<b;i++){
                nn[a][1].push_back(i);
                in[i]++;
            }
        else
            for(int i=b+1;i<a;i++){
                nn[a][1].push_back(i);
                in[i]++;
            }
    }
    for(int i=1;i<=N;i++){
        hg[i] = H;
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i : nn[cur][0]){
            hg[i] = hg[cur];
            in[i]--;
            if(!in[i]) q.push(i);
        }
        for(auto i : nn[cur][1]){
            hg[i] = hg[cur]-1;
            in[i]--;
            if(!in[i]) q.push(i);
        }
    }
    for(int i=1;i<=N;i++) printf("%d\n", hg[i]);
    return 0;
}
