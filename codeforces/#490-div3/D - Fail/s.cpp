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
    int n, m, mm[200010] = {0};
    ll nn[200010];
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &nn[i]);
        mm[nn[i]%m]++;
    }
    // ????
    
    return 0;
}
