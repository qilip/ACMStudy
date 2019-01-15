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
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef long long ll;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    int n, m;
    int nm[110][110] = {0};
    int ex[110][110] = {0};
    int x[] = {-1, 0, 1, 0};
    int y[] = {0, 1, 0, -1};
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char tmp;
            scanf(" %c", &tmp);
            if(tmp=='*'){
                nm[i][j] = 1;
                ex[i][j] = 1;
            }
        }
    }
    vector<tuple<int, int, int> > v;
    for(int i=2;i<=n-1;i++){
        for(int j=2;j<=m-1;j++){
            if(nm[i][j]){
                int cnt = 0;
                int flg = 1;
                while(flg){
                    for(int q=0;q<4;q++){
                        for(int p=0;p<=cnt+1;p++){
                            if(!nm[i+x[q]*p][j+y[q]*p]){
                                flg = 0;
                                goto OUT;
                            }
                        }
                    }
                    cnt++;
                }
                OUT:;
                if(cnt){
                    for(int q=0;q<4;q++){
                        for(int p=0;p<=cnt;p++){
                            ex[i+x[q]*p][j+y[q]*p] = 0;
                        }
                    }
                    v.emplace_back(i, j, cnt);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ex[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n", v.size());
    for(auto i : v){
        int a, b, c;
        tie(a, b, c) = i;
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
