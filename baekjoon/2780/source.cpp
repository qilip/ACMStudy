#include <stdio.h>
#include <vector>

using namespace std;

int pw[10][1010];
vector<int> v[10] = {
    {7},
    {2, 4},
    {1, 3, 5},
    {2, 6},
    {1, 5, 7},
    {2, 4, 6, 8},
    {3, 5, 9},
    {0, 4, 8},
    {5, 7, 9},
    {6, 8}
};

int main(void){
    for(int i=0;i<=9;i++) pw[i][1] = 1;
    for(int i=1;i<=999;i++){
        for(int j=0;j<=9;j++){
            pw[j][i] %= 1234567;
            for(auto &c : v[j]){
                pw[c][i+1] += pw[j][i];
            }
        }
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i=0;i<=9;i++){
            ans += pw[i][n];
        }
        printf("%d\n", ans%1234567);
    }
    return 0;
}
