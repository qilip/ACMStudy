#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    for(auto cur : v){
        int cnt = 0;
        for(auto i : v){
            if(cur.first < i.first && cur.second < i.second) cnt++;
        }
        printf("%d ", cnt+1);
    }
    return 0;
}
