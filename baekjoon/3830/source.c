#include <stdio.h>

int nw[100010];
int nn[100010];

int findp(int a){
    if(nn[a] == a) return a;
	int np = findp(nn[a]);
	nw[a] += nw[nn[a]];
	return nn[a] = np;
}

int ufind(int a, int b){
    int fa = findp(a);
    int fb = findp(b);
    if(fa==fb) return 1;
    return 0;
}

int main(void){
    while(1){
        int n, m;
        scanf("%d %d", &n, &m);
        if(!n && !m) break;
        for(int i=0;i<=n;i++){
            nn[i] = i;
			nw[i] = 0;
        }
        for(int i=0;i<m;i++){
            char c;
            scanf(" %c", &c);
            if(c=='!'){
                int a, b, w;
                scanf("%d %d %d", &a, &b, &w);
                int fa = findp(a);
                int fb = findp(b);
				if(fa == fb) continue;
				nw[fa] = nw[b] + w - nw[a];
				nn[fa] = fb;
            }else{
                int a, b;
                scanf("%d %d", &a, &b);
                if(ufind(a, b)) printf("%d\n", nw[a] - nw[b]);
                else printf("UNKNOWN\n");
            }
        }
    }
    return 0;
}