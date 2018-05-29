#include <stdio.h>

typedef long long ll;

int main(void){
    int n, nx[2010], ny[2010];
    ll answer = 0;
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        scanf(" %d", &nx[i]);
    }
    for(int i=0;i<n;i++){
        scanf(" %d", &ny[i]);
    }
    int xptr = 0;
    bool ptrflg = false;
    for(int i=0;i<n;i++){
        if(ptrflg){
            if( (ny[i]-nx[xptr])*(ny[i]-nx[xptr]) > (ny[i]-nx[xptr+1])*(ny[i]-nx[xptr+1]) ){
                xptr++;
                answer += (ny[i]-nx[xptr+1])*(ny[i]-nx[xptr+1]);
            }else{
                answer += (ny[i]-nx[xptr])*(ny[i]-nx[xptr]);
            }
        }else{
            answer += (ny[i]-nx[xptr])*(ny[i]-nx[xptr]);
            ptrflg = true;
        }
    }
    printf("%lld", answer);
    return 0;
}
