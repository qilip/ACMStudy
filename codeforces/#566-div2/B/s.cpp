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

    int h, w;
    char nn[510][510] = {0};
    scanf("%d %d", &h, &w);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            scanf(" %c", &nn[i][j]);
        }
    }
    int cnt = 0;
    int q[] = {0, 0, 1, -1};
    int p[] = {1, -1, 0, 0};
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(nn[i][j] == '*' && nn[i-1][j] == '*' && nn[i][j-1] == '*' && nn[i+1][j] == '*' && nn[i][j+1] == '*' && nn[i-1][j-1] == '.' && nn[i+1][j-1] == '.' && nn[i+1][j+1] == '.' && nn[i-1][j+1] == '.'){
                cnt++;
                for(int k=0;k<4;k++){
                    int z = 1;
                    while(1){
                        if(nn[i+q[k]*z][j+p[k]*z] == '*'){
                            nn[i+q[k]*z][j+p[k]*z] = '.';
                        }else{
                            break;
                        }
                        z++;
                    }
                }
                nn[i][j] = '.';
                goto E;
            }
        }
    }
    E:;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(nn[i][j] == '*') cnt = 2;
        }
    }
    if(cnt==1){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
