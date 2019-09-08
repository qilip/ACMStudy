#include <stdio.h>
#include <set>
#include <functional>

using namespace std;

int ar[4][4];
int x[] = {0, 1, 0, -1};
int y[] = {-1, 0, 1, 0};
set<int> s;

void run(int i, int j, int bef, int cnt){
    for(int a=0;a<4;a++){
        int ni = i+x[a];
        int nj = j+y[a];
        if( 0<=ni && ni<4 && 0<=nj && nj<4 ){
            int cur = bef*10 + ar[ni][nj];
            if(cnt==6){
                s.insert(cur);
            }else{
                run(ni, nj, cur, cnt+1);
            }
        }
    }
}

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        s.clear();
        printf("#%d ", t);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                scanf("%d", &ar[i][j]);
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                run(i, j, ar[i][j], 1);
            }
        }
        printf("%d\n", (int)s.size());
    }
    return 0;
}
