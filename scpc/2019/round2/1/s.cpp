#include <cstdio>

using namespace std;

bool notPrime[30010];
int cnt[30010];

int count(int cur){
    if(notPrime[cur]) return 0;
    if(cur < 10) return 1;
    if(cnt[cur] != -1) return cnt[cur];
    int max = 0;
    for(int i=1;cur/i;i*=10){
        int c = cur/(i*10)*i + cur%i;
        int a = count(c) + 1;
        if(a > max) max = a;
    }
    return cnt[cur] = max;
}

int main(void){
    int T;
    notPrime[0] = notPrime[1] = true;
    for(int i=2;i*i<=30000;i++){
        if(!notPrime[i]){
            for(int j=i*i;j<=30000;j+=i){
                notPrime[j] = true;
            }
        }
    }
    for(int i=0;i<=30000;i++){
        cnt[i] = -1;
    }
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int a, b;
        scanf("%d %d", &a, &b);
        int ca = count(a);
        int cb = count(b);
        printf("Case #%d\n", t);
        if(ca > cb) printf("1\n");
        else if(ca < cb) printf("2\n");
        else printf("3\n");
    }
    return 0;
}
