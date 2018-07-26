#include <stdio.h>

int ar[1000010];

int find(int a){
    if(ar[a] == a) return a;
    else return ar[a] = find(ar[a]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);
    ar[a] = b;
    return;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<=n;i++){
        ar[i] = i;
    }
    for(int i=0;i<m;i++){
        int c, a, b;
        scanf("%d %d %d", &c, &a, &b);
        if(!c){
            uni(a, b);
        }else{
            if(find(a)==find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
