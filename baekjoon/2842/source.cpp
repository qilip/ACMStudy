#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int n, nn[52][52]={0}, he[52][52]={0}, stx, sty, cnt;
int rng[2510], rcnt;
int x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y[] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<pair<int, int>> q;

bool is_pos(int h1, int h2){
    int ts[52][52], pcnt = cnt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ts[i][j] = he[i][j];
            if(nn[i][j]){
                if( !(h1<=he[i][j] && he[i][j] <= h2) ) goto BRK;
            }
        }
    }
    q.emplace(stx, sty);
    ts[stx][sty] = 0;
    while(!q.empty()){
        int nowx, nowy;
        tie(nowx, nowy) = q.front();
        q.pop();
        if(nn[nowx][nowy]) pcnt--;
        for(int i=0;i<8;i++){
            if( h1<=ts[nowx+x[i]][nowy+y[i]] && ts[nowx+x[i]][nowy+y[i]]<=h2 ){
                q.emplace(nowx+x[i], nowy+y[i]);
                ts[nowx+x[i]][nowy+y[i]] = 0;
            }
        }
    }
    if(pcnt==0) return true;
    BRK:;
    return false;
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char tmp;
            scanf(" %c", &tmp);
            if(tmp!='.') { nn[i][j] = 1; cnt++; }
            if(tmp=='P') { stx = i; sty = j; }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            scanf(" %d", &tmp);
            he[i][j] = tmp;
            rng[rcnt++] = tmp;
        }
    }
    sort(rng, rng+rcnt);
    int min = 0, max = 0, ans = 99999999;
    while(min<=max &&  max<rcnt){
        if(is_pos(rng[min], rng[max])){
            if(ans > rng[max]-rng[min]) ans = rng[max] - rng[min];
            min++;
        }else{
            max++;
        }
    }
    printf("%d", ans);
    return 0;
}
