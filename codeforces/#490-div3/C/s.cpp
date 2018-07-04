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
#include <tuple>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    scanf("%d %d", &n, &k);
    char s[400010];
    scanf("%s", s);
    for(char i='a';i<='z' && k;i++){
        for(int j=0;j<n && k;j++){
            if(s[j]==i){
                s[j] = 0;
                k--;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]!=0) printf("%c", s[i]);
    }
    return 0;
}
