#include <stdio.h>

int nw[100010];
int nn[100010];

int findp(int a, int bef){
    if(nn[a] == a) return a;
    if(bef) nw[bef] += nw[a];
    return nn[a] = findp(nn[a], a);
}

void uni(int a, int b){
    a = findp(a, 0);
    b = findp(b, 0);
    nn[a] = b;
}

int ufind(int a, int b){
    findp(a, 0);
    findp(b, 0);
    if(nn[a] && nn[a]==nn[b]) return 1;
    return 0;
}

int main(void){
    while(1){
        int n, m;
        scanf("%d %d", &n, &m);
        if(!n && !m) break;
        for(int i=0;i<=n;i++){
            nn[i] = i;
        }
        for(int i=0;i<m;i++){
            char c;
            scanf(" %c", &c);
            if(c=='!'){
                int a, b, w;
                scanf("%d %d %d", &a, &b, &w);
                if(nn[b]!=b){
                    nn[a] = b; nw[a] = -w;
                }else{
                    nn[b] = a; nw[b] = w;
                }
            }else{
                int a, b;
                scanf("%d %d", &a, &b);
                if(ufind(a, b)) printf("%d\n", nw[b] - nw[a]);
                else printf("UNKNOWN\n");
            }
        }
    }
    return 0;
}
