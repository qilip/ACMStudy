#include <cstdio>
#include <algorithm>

int main(void) {
    int N, na[100000], M, ma[100000];
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &na[i]);
    scanf("%d", &M);
    for(int i=0;i<M;i++) scanf("%d", &ma[i]);
    std::sort(na, na+N);
    for(int i=0;i<M;i++){
        int l = 0, r = N-1, m;
        while(l<=r) {
            m = l + (r-l)/2;
            if(ma[i]>na[m]) l = m+1;
            else if(ma[i]<na[m]) r = m-1;
            else if(ma[i]==na[m]) {
                printf("1\n");
                break;
            }
        }
        if(l>r) printf("0\n");
    }
    return 0;
}
