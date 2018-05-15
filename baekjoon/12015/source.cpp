#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int A, inp[1000010];
vector <int> dp;

int main(void){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    scanf("%d", &A);
    for(int i=0;i<A;i++){
        scanf("%d", &inp[i]);
    }
    for(int i=0;i<A;i++){
        auto p = lower_bound(dp.begin(), dp.end(), inp[i]);
        if(p == dp.end()){
            dp.push_back(inp[i]);
        }else{
            *p = inp[i];
        }
    }
    cout << dp.size();
    return 0;
}
