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

    int y;
    scanf("%d", &y);
    bool add = false;
    int cnt = 0;
    if( y%400==0 || (y%4==0 && y%100) ){
        add = true;
    }
    for(;;){
        bool ths = false;
        y++;
        if( y%400==0 || (y%4==0 && y%100) ){
            cnt++;
            ths = true;
        }
        cnt++;
        cnt%=7;
        if(add){
            if(cnt==0 && ths) break;
        } else if(cnt==0 && !ths) break;
    }
    printf("%d", y);
    return 0;
}
