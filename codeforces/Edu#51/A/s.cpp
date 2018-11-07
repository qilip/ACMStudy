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

    int t;
    scanf("%d", &t);
    while(t--){
        char s[110];
        scanf("%s", s);
        int len = strlen(s);
        int nulcnt = 3;
        int c[3] = {0}; // 소문자, 대문자 숫자 순서
        for(int i=0;i<len;i++){
            if( 'a' <= s[i] && s[i] <= 'z'){
                c[0]++;
            }else if( 'A' <= s[i] && s[i] <= 'Z'){
                c[1]++;
            }else{
                c[2]++;
            }
        }
        for(int i=0;i<3;i++){
            if(c[i]) nulcnt--;
        }
        if(nulcnt==1){
            if(!c[0]){
                if(c[1]>=2){
                    for(int i=0;i<len;i++){
                        if('A' <= s[i] && s[i] <= 'Z'){
                            s[i] = 'a';
                            break;
                        }
                    }
                }else{
                    for(int i=0;i<len;i++){
                        if('0' <= s[i] && s[i] <= '9'){
                            s[i] = 'a';
                            break;
                        }
                    }
                }
            }else if(!c[1]){
                if(c[0]>=2){
                    for(int i=0;i<len;i++){
                        if('a' <= s[i] && s[i] <= 'z'){
                            s[i] = 'A';
                            break;
                        }
                    }
                }else{
                    for(int i=0;i<len;i++){
                        if('0' <= s[i] && s[i] <= '9'){
                            s[i] = 'A';
                            break;
                        }
                    }
                }
            }else{
                if(c[1]>=2){
                    for(int i=0;i<len;i++){
                        if('A' <= s[i] && s[i] <= 'Z'){
                            s[i] = '1';
                            break;
                        }
                    }
                }else{
                    for(int i=0;i<len;i++){
                        if('a' <= s[i] && s[i] <= 'z'){
                            s[i] = '1';
                            break;
                        }
                    }
                }
            }
        }else if(nulcnt==2){
            if(c[0]){
                s[0] = 'A';
                s[1] = '1';
            }else if(c[1]){
                s[0] = 'a';
                s[1] = '1';
            }else{
                s[0] = 'A';
                s[1] = 'a';
            }
        }
        printf("%s\n", s);
    }
    
    return 0;
}
