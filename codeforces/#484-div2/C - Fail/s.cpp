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

int n, cnt;
int nn[100005];

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        nn[t1]++;
        nn[t2]++;
    }
    for(int i=1;i<=n;i++){
        if(nn[i]>=2){
            cnt+=nn[i]-1;
        }
    }
    if(cnt%2){
        printf("-1");
        return 0;
    }
    cnt/=2;
    printf("%d", cnt);
    return 0;
}
