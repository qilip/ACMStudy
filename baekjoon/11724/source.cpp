#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, p[1010];

int find(int cur){
    if(cur==p[cur]) return cur;
    return p[cur] = find(p[cur]);
}

int merge(int a, int b){
    a=find(a);
    b=find(b);
    if(a==b) return 0;
    p[b] = a;
    return 1;
}

int main(void){
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;i++){
        p[i]=i;
    }
    for(int i=1;i<=M;i++){
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        merge(tmp1, tmp2);
    }
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(p[i]==i) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
