#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int n, m, s, ans;
int nn[5010][5010];

void sfind(int now){
    for(int i=1;i<=n;i++){
        if(nn[now][i]){
            if(nn[s][i]==0){
                nn[s][i] = 1;
                sfind(i);
            }
        }
    }
}

int ufind(int cur){
    for(int i=1;i<=n;i++){
        if(nn[cur][i]){
            nn[cur][ufind(i)];
            // ㅁㄴㅇㄹ
        }
    }
}

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d %d %d", &n, &m, &s);
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);  
        nn[a][b] = 1;
    }
    nn[s][s] = 1;
    for(int i=1;i<=n;i++){
        ufind(i);
    }
    for(int i=1;i<=n;i++){
        if(!nn[s][i]){
            sfind(i);
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
