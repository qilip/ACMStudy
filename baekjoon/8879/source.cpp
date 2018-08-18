#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;

int main(void){
    int n, k;
    vector<tuple<int, int, int, int>> v;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a==k) a+=1000;
        v.emplace_back(b, c, d, a);
    }
    sort(v.begin(), v.end(), greater<tuple<int, int, int, int>>());
    for(int i=0;i<n;i++){
        if(k==get<3>(v[i])-1000){
            printf("%d", i+1);
            break;
        }
    }
    return 0;
}
