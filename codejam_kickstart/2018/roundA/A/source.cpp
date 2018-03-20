#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;

int num[20];

int numb(long long a){
    int s=0;
    for(;a>0;a=a/10){
        s++;
        num[s] = a%10;
    }
    return s;
}

long long powers(int b){
    long long tmp=10;
    if(b==0) return 1;
    for(;b>1;b--){
        tmp = tmp*10;
    }
    return tmp;
}

int main(void){
    int T;
    long long n, cnt, out[110];
    FILE *fr = fopen("A-large.in","r");
    FILE *fw = fopen("output.txt","w");
    fscanf(fr, "%d", &T);
    for(int i=1;i<=T;i++){
        long long cnta=0, cntb=0;
        fscanf(fr, "%lld", &n);
        long long n2 = n;
        int numbbs = numb(n);
        for(int j=numbbs; j>=1;j--){
            if(num[j]%2){
                long long a = powers(j-1);
                long long tmp = n%a;
                cntb += tmp+1; // 수 내리기
                long long tmpp = j-2;
                for(;tmpp>=0;tmpp--){
                    long long tmps = powers(tmpp);
                    cntb += tmps;
                }
                break;
            }
        }
        A:;
        numbbs = numb(n2);
        for(int j=numbbs; j>=1;j--){
            if(num[j]%2){
                long long a = powers(j-1);
                long long tmp = n2%a;
                cnta += a-tmp; // 수 올리기
                n2 += a-tmp;
                goto A;
            }
        }
        out[i] = min(cnta, cntb);
    }
    for(int i=1;i<=T;i++){
        fprintf(fw, "Case #%d: %lld\n",i , out[i]);
    }
}
