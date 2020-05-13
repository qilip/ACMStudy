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
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n;
        char p[52][110] = {0};
        char ans[10010] = {0};
        char suffix[110] = {0};
        int suflen = 0;
        int ansp = 0;
        bool ansask = false;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf(" %s", p[i]);
        }
        char pl = 0;
        char pr = 0;
        int len[52] = {0};
        for(int i=0;i<n;i++){
            if(p[i][0]!='*'){
                if(!pl){
                    pl = p[i][0];
                }else if(pl != p[i][0]){
                    ansask = true;
                }
            }
            len[i] = strlen(p[i]);
            if(p[i][len[i]-1]!='*'){
                if(!pr){
                    pr = p[i][len[i]-1];
                }else if(pr != p[i][len[i]-1]){
                    ansask = true;
                }
            }
        }
        if(!ansask){
            if(pl){
                bool pass[52] = {0};
                for(int i=0;i<*max_element(len, len+n);i++){
                    if(ansask) break;
                    for(int j=0;j<n;j++){
                        if(pass[j]) continue;
                        if(i >= len[j]) pass[j] = true;
                        else if(p[j][i] == '*') pass[j] = true;
                        else if(!ans[i]) ans[ansp++] = p[j][i];
                        else if(ans[i] != p[j][i]) ansask = true;
                    }
                }
                // printf("pre: %s | ", ans);
            }
            if(pr){
                bool pass[52] = {0};
                for(int i=0;i<*max_element(len, len+n);i++){
                    if(ansask) break;
                    for(int j=0;j<n;j++){
                        if(pass[j]) continue;
                        if(len[j]-i-1 < 0) pass[j] = true;
                        else if(p[j][len[j]-i-1] == '*') pass[j] = true;
                        else if(!suffix[i]) suffix[i] = p[j][len[j]-i-1];
                        else if(suffix[i] != p[j][len[j]-i-1]) ansask = true;
                    }
                }
                suflen = strlen(suffix);
                for(int i=0;i<suflen/2;i++){
                    swap(suffix[i], suffix[suflen-1-i]);
                }
                // printf("suf: %s | ", suffix);
            }
            for(int i=0;i<n;i++){
                int j = 0;
                char tmp[110] = {0};
                int tmpp = 0;
                for(;p[i][j];j++){
                    if(p[i][j] == '*'){
                        j++;
                        break;
                    }
                }
                while(p[i][j]){
                    if(p[i][j] == '*'){
                        for(int k=0;k<tmpp;k++){
                            ans[ansp++] = tmp[k];
                        }
                        tmpp = 0;
                    }else{
                        tmp[tmpp++] = p[i][j];
                        tmp[tmpp] = 0;
                    }
                    j++;
                }
            }
            if(pr){
                for(int i=0;i<suflen;i++){
                    ans[ansp++] = suffix[i];
                }
            }
        }
        if(!ansp){
            ans[ansp++] = 'A';
        }

        printf("Case #%d: ", t);
        if(ansask) printf("*\n");
        else printf("%s\n", ans);
    }
    return 0;
}
