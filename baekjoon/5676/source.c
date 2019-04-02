#include <stdio.h>

int x[400010];
void update(int node, int idx, int value, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){ x[node] = value; return; }
    int m = (l+r)/2;
    update(node*2, idx, value, l, m);
    update(node*2+1, idx, value, m+1, r);
    x[node] = x[node*2] * x[node*2+1];
    return;
}

int find(int node, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 1;
    if(fl<=l && r<=fr) return x[node];
    int m = (l+r)/2;
    return find(node*2, fl, fr, l, m) * find(node*2+1, fl, fr, m+1, r);
}

int main(void){
    int n, k;
    while(~scanf("%d %d", &n, &k)){
        for(int i=1;i<=n;i++){
            int t;
            scanf("%d", &t);
            if(t>0) t = 1;
            if(t<0) t = -1;
            update(1, i, t, 1, n);
        }
        for(int i=1;i<=k;i++){
            char s;
            int a, b;
            scanf(" %c %d %d", &s, &a, &b);
            if(s == 'C'){
                if(b>0) b = 1;
                if(b<0) b = -1;
                update(1, a, b, 1, n);
            }else{
                int q = find(1, a, b, 1, n);
                if(q>0) printf("+");
                if(q<0) printf("-");
                if(q==0) printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}
