#include <stdio.h>
#include <vector>

using namespace std;

int T, col[20010];
vector<int> v[20010];
bool ans = true;

void dfs(const vector<int> &vec, int sel, int color){
    if(!col[sel]) col[sel] = color;
    for(int i : vec){
        if(!col[i]){
            col[i] = 3-color;
            dfs(v[i], i, 3-color );
        }else{
            if(col[i]==color){
                ans = false;
                return;
            }
        }
    }
}

int main(void){
    scanf("%d", &T);
    while(T--){
        int V, E;
        ans = true;
        scanf("%d %d", &V, &E);
        for(int i=0;i<=V;i++){
            v[i].clear();
            col[i] = 0;
        }
        for(int i=0;i<E;i++){
            int a, b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<=V;i++){
            if(!col[i])
                dfs(v[i], i, 1);
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
