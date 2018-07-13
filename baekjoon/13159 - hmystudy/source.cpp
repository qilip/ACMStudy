#include <stdio.h>

using namespace std;

typedef long long ll;

struct node{
    int p, l, r;
    int val, min, max;
    ll sum;
    int is_rev, size;
};

int root;
node tree[300010];

void update(int c){

}

void rotate(int c){
    if(c==root) return;
    int p = tree[c].p;
    int gp = tree[p].p;
    int r = tree[c].r;
    int l = tree[c].l;
    int is_pleft = 0;
    int is_gpleft = 0;
    if(tree[p].l==c) is_pleft = 1;
    if(p==root){
        root = c;
        tree[c].p = -1;
    }else{
        if(tree[gp].l==p) is_gpleft = 1;
        if(is_gpleft){
            tree[gp].l = c;
        }else{
            tree[gp].r = c;
        }
        tree[c].p = gp;
    }
    if(is_pleft){
        tree[p].l = tree[c].r;
        tree[r].p = p;
        tree[c].r = p;
    }else{
        tree[p].r = tree[c].l;
        tree[l].p = p;
        tree[c].l = p;
    }
    tree[p].p = c;
    update(p);
    update(c);
}

void splay(){

}

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    // p, l, r, val, min, max, (ll) sum, is_rev, size;
    tree[0] = {0, 0, 0, 0, 2100000000, -1};
    tree[1] = {-1, 0, 0, 1, 1, 1, 1};
    for(int i=2;i<=n;i++){
        tree[i-1].r = i;
        tree[i] = {i-1, 0, 0, i, 1, i};
        tree[i].sum = tree[i-1].sum + i;
    }
    while(n--){

    }
    return 0;
}
