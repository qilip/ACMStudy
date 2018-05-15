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

    int n;
    scanf("%d", &n);
    char kuros[100005];
    char shiros[100005];
    char katies[100005];
    int kuroalp[256] = {0};
    int shiroalp[256] = {0};
    int katiealp[256] = {0};
    scanf("%s", kuros);
    scanf("%s", shiros);
    scanf("%s", katies);
    int len = strlen(kuros);
    for(int i=0;i<len;i++){
        kuroalp[kuros[i]-'0']++;
        shiroalp[shiros[i]-'0']++;
        katiealp[katies[i]-'0']++;
    }

    sort(kuroalp, kuroalp+256, greater<int>());
    sort(shiroalp, shiroalp+256, greater<int>());
    sort(katiealp, katiealp+256, greater<int>());

    int kuromax = kuroalp[0] + n;
    int shiromax = shiroalp[0] + n;
    int katiemax = katiealp[0] + n;
    int kuromaxx = 0, shiromaxx = 0, katiemaxx = 0;
    if(kuromax>len || shiromax>len || katiemax>len ){
        for(int i=0;i<256;i++){
            kuromax = kuroalp[i] + n;
            shiromax = shiroalp[i] + n;
            katiemax = katiealp[i] + n;
            if( kuromax >= len && !((kuromax - len)%2) ) kuromaxx = len;
            if( shiromax >= len && !((shiromax - len)%2) ) shiromaxx = len;
            if( katiemax >= len && !((katiemax - len)%2) ) katiemaxx = len;
            if(kuromax < len && kuromaxx < kuromax) kuromaxx = kuromax;
            if(shiromax < len && shiromaxx < shiromax) shiromaxx = shiromax;
            if(katiemax < len && katiemaxx < katiemax) katiemaxx = katiemax;
        }
    }else{
        kuromaxx = kuromax; shiromaxx = shiromax; katiemaxx = katiemax;
    }

    if(kuromaxx > shiromaxx && kuromaxx > katiemaxx){
        printf("Kuro");
    }else if(shiromaxx > kuromaxx && shiromaxx > katiemaxx){
        printf("Shiro");
    }else if(katiemaxx > kuromaxx && katiemaxx > shiromaxx){
        printf("Katie");
    }else{
        printf("Draw");
    }
    return 0;
}
