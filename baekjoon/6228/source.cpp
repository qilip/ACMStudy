#include <stdio.h>
#include <vector>

using namespace std;

int n, s, e;
vector<int> w[21], r[21];
int dic[9];
int cnt;

void chk(){
    for(int i=0;i<e;i++){
        for(int j=0;j<r[i].size();j++)
            if(dic[r[i][j]] < w[i][j]) goto E;
        cnt++;
        return;
        E:;
    }
}

void run(int dep){
    if(dep==n){ chk(); return; }
    for(int i=1;i<=s;i++){
        dic[i]++;
        run(dep+1);
        dic[i]--;
    }
}

int main(void){
    scanf("%d %d %d", &n, &s, &e);
    for(int i=0;i<e;i++){
        char s;
        do{
            int a, b;
            s = 0;
            scanf("%dx%d", &a, &b);
            w[i].push_back(a);
            r[i].push_back(b);
            scanf("%c", &s);
        }while(s=='+');
    }
    run(0);
    printf("%d", cnt);
    return 0;
}
