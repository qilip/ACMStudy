#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>

using namespace std;
long long nn[300010][2];
int main(void){
    int n, a, b;
    vector< pair<long long, int> > v;
    scanf("%d %d %d", &n, &a, &b);
    int aa = 1<<a;
    long long max = 0, maxt = 0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        scanf("%d %d", &nn[i][0], &nn[i][1]);
        v.emplace_back(nn[i][0] - nn[i][1], i);
        if(a){
            int tmp = nn[i][0]*aa;
            if(max < tmp-nn[i][1]){
                max = tmp-nn[i][i];
                maxt = tmp;
                maxi = i;
            }
        }
    }
    if(a){
        nn[maxi][0] = maxt;
        v[maxi].first = maxt - nn[maxi][1];
    }
    sort(v.begin(), v.end());
    int vptr = n-1;
    for(int i=0;i<b;i++){
        if(vptr<0) break;
        if(v[vptr].first<=0) break;
        int as = v[vptr].second;
        long long tmp = nn[as][0];
        nn[as][0] = nn[as][1];
        nn[as][1] = tmp;
        vptr--;
    }
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += nn[i][1];
    }
    printf("%lld", sum);
    return 0;
}
