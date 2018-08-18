#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
int chk[10];
vector<int> v;

void r(int d){
    if(d>m){
        for(auto i : v){
            printf("%d ", i);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(chk[i]) continue;
        chk[i] = 1;
        v.push_back(i);
        r(d+1);
        chk[i] = 0;
        v.pop_back();
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    r(1);
    return 0;
}
