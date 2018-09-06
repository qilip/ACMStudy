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

    int n, k;
    char s[100];
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int pnt = 0, run = 0;
    for(int i=1;i<n;i++){
        bool flg = true;
        for(int j=i, nt = 0;j<n;j++, nt++){
            if(s[nt] != s[j]){
                flg = false;
                break;
            }
        }
        if(flg){
            run = 1;
            pnt = i;
            break;
        }
    }
    if(!run){
        for(int i=0;i<k;i++){
            printf("%s", s);
        }
    }else{
        for(int i=0;i<k-1;i++){
            for(int j=0;j<pnt;j++){
                printf("%c", s[j]);
            }
        }
        printf("%s", s);
    }
    return 0;
}
