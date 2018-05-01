#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

int L, C;
char ac[20];

void hehe(int cnt, int aeiou, int zaum, int seted, string ans){
    if(cnt>C) return;
    if(seted==L){
        if(aeiou>=1 && zaum >= 2){
            cout << ans <<endl;
        }
        return;
    }
    int ae = 0, za = 0;
    if(ac[cnt] == 'a' || ac[cnt] == 'e' || ac[cnt] == 'i' || ac[cnt] == 'o' || ac[cnt] == 'u'){
        ae = 1;
    }else{
        za = 1;
    }
    string anss = ans;    
    ans += ac[cnt];
    hehe(cnt+1, aeiou+ae, zaum+za, seted+1, ans);
    hehe(cnt+1, aeiou, zaum, seted, anss);
}

int main(void){
    scanf("%d %d", &L, &C);
    for(int i=0;i<C;i++){
        scanf(" %c", &ac[i]);
    }
    sort(ac, ac+C);
    hehe(0, 0, 0, 0, {});
    return 0;
}
