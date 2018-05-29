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

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, nn[400] = {0}, cnteven = 0, cntodd = 0;
    scanf("%d", &n);
    for(int i=1;i<=n/2;i++){
        scanf(" %d", &nn[i]);
    }
    sort(nn+1, nn+n/2+1);
    for(int i=n-1;i>0;i-=2){
        cntodd += abs(i-nn[(i+1)/2]);
    }
    for(int i=n;i>0;i-=2){
        cnteven += abs(i-nn[i/2]);
    }
    printf("%d", cnteven > cntodd ? cntodd : cnteven);
    return 0;
}
