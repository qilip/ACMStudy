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
    char ch[1100];
    memset(ch, '0', sizeof(ch));
    scanf("%d", &n);
    scanf(" %s", ch);
    bool back = false, flg = true;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(ch[i]=='1'){
            cnt++;
            if(back || ch[i+1]=='1') { flg = false; break; }
            back = true;
        }else{
            back = false;
        }
    }
    if(cnt!=(n+1)/2) flg = false;
    if(flg) printf("Yes");
    else printf("No");
    return 0;
}
