// #include <bits/stdc++.h>

/* codeforces printf %Lf problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
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
    // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, k, nn[600];
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    double min = numeric_limits<double>::max();
    for(int i=0;i<n-k+1;i++){
        int sum = 0;
        for(int j=0;j<k;j++){
            sum += nn[i+j];
        }
        double avg = (double)sum/(double)k;
        double bun = 0.0;
        for(int j=0;j<k;j++){
            bun += ((double)nn[i+j]-avg)*((double)nn[i+j]-avg);
        }
        double kbun = bun / (double)k;
        double sq = sqrt(kbun);
        if(sq<min) min = sq;
        for(int q=1;i+k-1+q<n;q++){
            sum += nn[i+k-1+q];
            avg = (double)sum/(double)(k+q);
            bun = 0;
            for(int j=0;j<k+q;j++){
                bun += ((double)nn[i+j]-avg)*((double)nn[i+j]-avg);
            }
            double kbun = bun / (double)(k+q);
            double sq = sqrt(kbun);
            if(sq<min) min = sq;
        }
    }
    printf("%.11f", min);
    return 0;
}
