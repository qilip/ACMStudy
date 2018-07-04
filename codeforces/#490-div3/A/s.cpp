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
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, nn[120] = {0}, ans = 0;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    for(int i=0;i<n;i++){
        if(nn[i]<=k) ans++;
        else break;
    }
    int cnt = ans;
    for(int i=n-1;i>cnt;i--){
        if(nn[i]<=k) ans++;
        else break;
    }
    printf("%d", ans);
    return 0;
}
