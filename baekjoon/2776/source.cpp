#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        vector<int> a;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            int t;
            scanf("%d", &t);
            a.push_back(t);
        }
        sort(a.begin(), a.end());
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            int t;
            scanf("%d", &t);
            if(binary_search(a.begin(), a.end(), t)) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
