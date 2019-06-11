#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int matk[9];
int mhp[9];
int yatk[9];
int yhp[9];

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    if(m==0){
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d", &matk[i], &mhp[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d", &yatk[i], &yhp[i]);
    }

    vector<pair<int ,int>> m;
    vector<pair<int ,int>> y;
    
    do{

    }while(0);

    return 0;
}
