// #include <bits/stdc++.h>

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

    char s;
    int cnt = 0;
    int ri = 0;
    s = getchar();
    while(s!=EOF){
        switch(cnt){
            case 0:
                if(s=='U') cnt = 1;
                break;
            case 1:
                if(s=='C') cnt = 2;
                break;                
            case 2:
                if(s=='P') cnt = 3;
                break;
            case 3:
                if(s=='C') cnt = 4;
                break;
        }
        if(cnt==4){
            ri = 1;
            break;
        }
        s = getchar();
    }
    if(ri) printf("I love UCPC");
    else printf("I hate UCPC");
    return 0;
}
