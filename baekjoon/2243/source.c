#include <stdio.h>

int tree[4000010];

void update(int cur, int idx, int diff, int l, int r){
    if(idx<l || r<idx) return;
    if(l==r){
        tree[cur] += diff;
        return;
    }
    int m = (l+r)/2;
    update(cur*2, idx, diff, l, m);
    update(cur*2+1, idx, diff, m+1, r);
    tree[cur] = tree[cur*2] + tree[cur*2+1];
}

int find(int cur, int fl, int fr, int l, int r){
    if(fr<l || r<fl) return 0;
    if(fl<=l && r<=fr) return tree[cur];
    int m = (l+r)/2;
    return find(cur*2, fl, fr, l, m) + find(cur*2+1, fl, fr, m+1, r);
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a, b, c;
        scanf("%d", &a);
        if(a==1){
            scanf("%d", &b);
            int l = 1, r = 1000000;
            int m;
            int ans = 99999999;
            while(l<=r){
                m = (l+r)/2;
                int res = find(1, 1, m, 1, 1000000);
                if(res>=b){
                    ans = m;
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
            printf("%d\n", ans);
            update(1, ans, -1, 1, 1000000);
        }else{
            scanf("%d %d", &b, &c);
            update(1, b, c, 1, 1000000);
        }
    }
    return 0;
}
