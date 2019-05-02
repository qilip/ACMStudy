#include <stdio.h>
#include <string.h>

int tree[800000];
int ix[100010];

void update(int cur, int idx, int diff, int l, int r){
    if(idx<l || r<idx) return;
    tree[cur] += diff;
    if(l != r){
        int m = (l+r)/2;
        update(cur*2, idx, diff, l, m);
        update(cur*2+1, idx, diff, m+1, r);
    }
}

int find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(tree, 0, sizeof tree);
        memset(ix, 0, sizeof ix);
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i=n;i>=1;i--){
            update(1, n-i+1, 1, 1, n+m);
            ix[n-i+1] = i;
        }
        for(int i=1;i<=m;i++){
            int c;
            scanf("%d", &c);
            printf("%d ", find(1, ix[c]+1, n+i-1, 1, n+m));
            update(1, ix[c], -1, 1, n+m);
            ix[c] = n+i;
            update(1, ix[c], 1, 1, n+m);
        }
        printf("\n");
    }
    return 0;
}
