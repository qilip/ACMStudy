#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(void){
    int n;
    vector<pair<int, int>> v;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        v.emplace_back(y, x);
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        printf("%d %d\n", i.second, i.first);
    }
    return 0;
}
