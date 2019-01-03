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

    int n;
    int b[100010];
    int pos[] = {-1, 0, 1};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }
    int mcng = 2000000;
    for(int q=0;q<3;q++){
        for(int p=0;p<3;p++){
            int cng = abs(pos[q]) + abs(pos[p]);
            int cha = b[1] - b[0] + pos[q] - pos[p];
            int bef = pos[q];
            int clr = 1;
            for(int i=2;i<n;i++){
                int flg = 0;
                for(int w=0;w<3;w++){
                    int cur = b[i] - b[i-1] + pos[w] - bef;
                    if(cur==cha){
                        cng += abs(pos[w]);
                        bef = pos[w];
                        flg = 1;
                        break;
                    }
                }
                if(!flg){
                    clr = 0;
                    break;
                }
            }
            if(clr){
                mcng = mcng > cng ? cng : mcng;
            }
        }
    }
    if(mcng == 2000000) printf("-1");
    else printf("%d", mcng);
    return 0;
}
