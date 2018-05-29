#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int nk[100005];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    for(int i=0;i<n*k;i++){
        scanf("%d", &nk[i]);
    }
    sort(nk, nk+n*k);
    if(nk[n-1]-nk[0]>l){
        printf("0");
    }else{
        for(int i=(n-1)*k;i>=0;i--){
            if(nk[i]-nk[0]<=l){
                long long sum = 0;
                int ptr = n*k-1-i+1;
                int cnt = n;
                while(i>=0){
                    if(ptr>=k){
                        sum += nk[i];
                        ptr -= k;
                        cnt--;
                    }
                    if(cnt==0) break;
                    i--;
                    ptr++;
                }
                printf("%lld", sum);
                return 0;
            }
        }
    }
    
    return 0;
}
