// #include <bits/stdc++.h>

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

    int n, k;
    int a[5010];
    double dmax = 0;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=0;i<n-k+1;i++){
        int tsum = 0;
        for(int q=i;q<i+k;q++){
            tsum += a[q];
        }
        if(tsum/(double)k > dmax) dmax = tsum/(double)k;
        int rc = 0;
        for(int j=i+k;j<n;j++){
            tsum += a[j];
            rc++;
            if(tsum/(double)(k+rc) > dmax) dmax = tsum/(double)(k+rc);
        }

    }
    printf("%f", dmax);
    return 0;
}
