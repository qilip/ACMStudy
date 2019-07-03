#include <stdio.h>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

int main(void){
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    bool ff[100'0010] = {false};
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    ff[s] = true;
    while(!q.empty()){
        int cur, cnt;
        tie(cur, cnt) = q.front();
        q.pop();
        if(cur == g){ printf("%d", cnt); return 0; }
        if(cur+u <= f && !ff[cur+u]){ q.emplace(cur+u, cnt+1); ff[cur+u] = true; }
        if(cur-d >= 1 && !ff[cur-d]){ q.emplace(cur-d, cnt+1); ff[cur-d] = true; }
    }
    printf("use the stairs");
    return 0;
}
