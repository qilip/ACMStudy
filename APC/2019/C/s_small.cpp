#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int matk;
int mhp;
int yatk[9];
int yhp[9];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    if(m==0){
        printf("0");
        return 0;
    }
    if(n==0){
        matk = 0;
        mhp = 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d", &matk, &mhp);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d", &yatk[i], &yhp[i]);
    }
    for(int i=0;i<=m;i++){
        int tmatk, tmhp;
        tmatk = matk;
        tmhp = mhp;
        int tatk[9], thp[9];
        for(int q=1;q<=m;q++){
            tatk[q] = yatk[q];
            thp[q] = yhp[q];
        }
        bool md = false;
        int dcnt = 0;
        if(i){
            tmhp -= tatk[i];
            thp[i] -= tmatk;
            if(tmhp<=0) md = true;
            if(thp[i]<=0) dcnt = 1;
        }
        //attack;
        //can i modok?
        //dmg
        for(int j=1;j<=m+1;j++){
            if(dcnt==m) break;
            bool us = false;
            for(int k=1;k<=m;k++){
                if(thp[k] == j){
                    thp[k] = 0;
                    dcnt++;
                    us = true;
                }
            }
            if(md == false){
                if(tmhp == j){
                    us = true;
                    md = true;
                }
            }
            if(!us) break;
        }
        if(dcnt == m){
            if(i) printf("2\n");
            else printf("1\n");
            if(i) printf("attack 1 %d\n", i);
            printf("use modok");
            return 0;
        }
    }
    printf("-1");
    return 0;
}
