#include <stdio.h>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

int main(void){
    int t;
    int not_prime[10000] = {0};
    scanf("%d", &t);
    for(int i=2;i<100;i++){
        if(not_prime[i]) continue;
        for(int j=i*i; j<=10000;j+=i){
            not_prime[j] = 1;
        }
    }
    for(int T=0;T<t;T++){
        int a, b;
        queue<pair<int, int>> q;
        int checked[10000] = {0};
        scanf("%d %d", &a, &b);
        q.emplace(0, a);
        checked[a] = 1;
        int flg = 1;
        while(!q.empty()){
            int cost, cur;
            tie(cost, cur) = q.front();
            q.pop();
            if(cur==b){
                printf("%d\n", cost);
                flg = 0;
                break;
            }
            for(int i=1;i<=1000;i*=10){
                int next = cur - cur/i%10*i;
                for(int j=0;j<=9;j++){
                    int cnxt = next+i*j;
                    if(!not_prime[cnxt] && cnxt >=1000 && cnxt <=9999 && !checked[cnxt]){
                        q.emplace(cost+1, cnxt);
                        checked[cnxt] = 1;
                    }
                }
            }
        }
        if(flg) printf("Impossible\n");
    }
    return 0;
}
