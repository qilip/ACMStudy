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

int n, ptr = 0;
vector<pair<int, int>> inp;
vector<int> v;

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int tin;
        scanf("%d", &tin);
        inp.emplace_back(tin, i);
    }
    sort(inp.begin(), inp.end());
    for(int i=0;i<n*2;i++){
        char tmp;
        scanf(" %c", &tmp);
        if(tmp=='0'){
            int seat = inp[ptr].second;
            ptr++;
            v.push_back(seat);
            printf("%d ", seat);
        }else{
            printf("%d ", v.back());
            v.pop_back();
        }
    }
    return 0;
}
