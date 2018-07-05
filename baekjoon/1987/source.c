#include <stdio.h> 

int r, c, maxx;
char rc[22][22];
int x[] = {-1, 0, 1, 0}, y[] = {0, 1, 0, -1};
int chk[26];

void dfs(int nx, int ny, int dep){
    if(chk[rc[nx][ny]-'A']) return;
    chk[rc[nx][ny]-'A'] = 1;
    for(int i=0;i<4;i++){
        if(rc[nx+x[i]][ny+y[i]]){
            dfs(nx+x[i], ny+y[i], dep+1);
        }
    }
    chk[rc[nx][ny]-'A'] = 0;
    if(dep>maxx) maxx = dep;
}

int main(void){
    scanf("%d %d", &r, &c);
    for(int i=1;i<=r;i++){
        scanf("%s", rc[i]+1);
    }
    chk[rc[0][0]-'A'] = 1;
    dfs(1, 1, 1);
    printf("%d", maxx);
    return 0;
}
