#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int inp[1000010];
vector<int> dp;

int main(void){
    int A;
    scanf("%d", &A);
    for(int i=0;i<A;i++){
        scanf("%d", &inp[i]);
    }
    for(int i=0;i<A;i++){
        auto it = lower_bound(dp.begin(), dp.end(), inp[i]);
        if(it == dp.end()){
            dp.push_back(inp[i]);
        }else{
            *it = inp[i];
        }
    }
    
    cout << dp.size();
    return 0;
}
