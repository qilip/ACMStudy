#include <stdio.h>
#include <string.h>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

int powi(int a){
    int r = 1;
    while(a--){
        r *= 10;
    }
    return r;
}

int main(void){
    int str = 0, end = 123456780;
    int arr[10][4] = {
        {0},
        {2, 4},
        {1, 3, 5},
        {2, 6},
        {1, 5, 7},
        {2, 4, 6, 8},
        {3, 5, 9},
        {4, 8},
        {5, 7, 9},
        {6, 8}
    };
    int wz = 1;
    for(int i=1;i<=9;i++){
        int tmp;
        scanf(" %1d", &tmp);
        if(tmp==0) wz = i;
        str *= 10;
        str += tmp;
    }
    queue<tuple<char, char, int>> q;
    set<int> s;
    q.emplace(0, wz, str);
    s.insert(str);
    while(!q.empty()){
        char cost, zro;
        int cur;
        tie(cost, zro, cur) = q.front();
        q.pop();
        if(cur==end){
            printf("%u", cost);
            return 0;
        }
        int cur_zro = powi(9-zro);
        for(int i=0;i<4 && arr[(int)zro][i];i++){
            int nxt_zro = powi(9-arr[(int)zro][i]);
            int swp = cur/nxt_zro%10;
            int ncur = cur;
            ncur += swp*cur_zro;
            ncur -= swp*nxt_zro;
            if(!s.count(ncur)){
                q.emplace(cost+1, arr[(int)zro][i], ncur);
                s.insert(ncur);
            }
        }
    }
    printf("-1");
    return 0;
}
