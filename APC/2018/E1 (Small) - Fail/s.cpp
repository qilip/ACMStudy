#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, nn[300010];

ll answer;

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    sort(nn, nn+n);
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            int majo = (nn[j]-nn[i])%1000000007;
            int lop = j-i-1;
            if(majo==0) continue;
            if(lop>=60){
                ll tmp = 1;
                while(lop>=60){
                    tmp *= ((1LL << 60)%1000000007);
                    lop -= 60;
                }
                tmp *= ((1LL << lop)%1000000007);
                tmp%=1000000007;
                answer += tmp*majo;
            }else{
                answer += ((1 << lop)%1000000007)*majo;
            }
            answer%=1000000007;
        }
    }
    printf("%lld", answer);
    return 0;
}
