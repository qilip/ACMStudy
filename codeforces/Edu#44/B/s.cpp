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

    int n, m;
    char nm[2010][2010] = {0};

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%s", nm[i]);
    }
    int mflg = 0;
    for(int i=0;i<n;i++){
        int iflg = 1;
        for(int j=0;j<m;j++){
            if(nm[i][j]=='1'){
                int flg = 1;
                for(int k=0;k<n;k++){
                    if(k==i) continue;
                    if(nm[k][j]=='1') { flg = 0; break; }
                }
                if(flg) { iflg = 0;  break; }
            }
        }
        if(iflg) { mflg = 1; break; }
    }
    if(mflg) printf("YES");
    else printf("NO");
    return 0;
}
