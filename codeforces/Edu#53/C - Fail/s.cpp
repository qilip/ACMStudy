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

int n;
int s[200010];
int x, y;
int cx, cy;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char tmp;
        scanf(" %c", &tmp);
        switch(tmp){
            case 'U':
                s[i] = 1;
                cy++;
                break;
            case 'D':
                s[i] = 2;
                cy--;
                break;
            case 'R':
                s[i] = 3;
                cx++;
                break;
            case 'L':
                s[i] = 4;
                cx--;
                break;
        }
    }
    scanf("%d %d", &x, &y);
    if(cx==x && cy==y){
        printf("0");
        return 0;
    }
    int mg = n - abs(x) - abs(y);
    if( abs(x) + abs(y) > n || mg%2 ){
        printf("-1");
        return 0;
    }
    int ny = (y-cy)/2, nx = (x-cx)/2;
    int c[5] = {0};
    if(ny>0) c[2] = ny;
    else c[1] = -ny;
    if(nx>0) c[4] = nx;
    else c[3] = -nx;

    int st = 0, mini = n;
    int cng[5] = {0};

    for(int i=0;i<n;i++){
        if(c[s[i]]) cng[s[i]]++;
        while(st<i){
            if(!c[s[st]] || cng[s[st]]-1 >= c[s[st]]) st++;
            else break;
        }
        int flg = 1;
        for(int q=1;q<=4;q++){
            if(cng[q] < c[q]) flg = 0;
        }
        if(flg) mini = mini>i-st+1 ? i-st+1 : mini;
    }
    printf("%d", mini);
    return 0;
}
