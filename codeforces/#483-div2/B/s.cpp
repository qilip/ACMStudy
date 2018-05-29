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

    int n, m;
    char nm[120][120] = {0};
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%s", nm[i]+1);
    }
    int flg = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nm[i][j]-'0' < 9 && nm[i][j]-'0' > 0){
                int cnt = 0;
                for(int mi=i-1;mi<=i+1;mi++){
                    for(int mj=j-1;mj<=j+1;mj++){
                        if(nm[mi][mj]=='*') cnt++;
                    }
                }
                if( (nm[i][j]-'0')!=cnt ) { flg = 1; break; }
            }else if(nm[i][j]=='.'){
                int cnt = 0;
                for(int mi=i-1;mi<=i+1;mi++){
                    for(int mj=j-1;mj<=j+1;mj++){
                        if(nm[mi][mj]=='*') cnt++;
                    }
                }
                if(cnt) { flg = 1; break; };
            }
        }
    }
    if(flg) printf("NO");
    else printf("YES");
    return 0;
}
