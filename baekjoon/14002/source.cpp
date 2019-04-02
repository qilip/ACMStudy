#include <stdio.h>
#include <vector>

using namespace std;

int main(void){
    int n;
    int nn[1010];
    int dp[1010] = {0};
    int q[1010] = {0};
    vector<int> v;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &nn[i]);
    }
    int max = 0, maxi = 0;
    for(int i=1;i<=n;i++){
        int cur = 0;
        for(int j=0;j<i;j++){
            if(nn[i] > nn[j]){
                if(cur < dp[j]){
                    cur = dp[j];
                    q[i] = j;
                }
            }
        }
        dp[i] = cur + 1;
        if(max < dp[i]){
            max = dp[i];
            maxi = i;
        }
    }
    printf("%d\n", max);
    int cur = maxi;
    v.push_back(nn[cur]);
    do{
        v.push_back(nn[q[cur]]);
        cur = q[cur];
    }while(cur);
    v.pop_back();
    for(auto i=v.rbegin();i<v.rend();i++) printf("%d ", *i);
    return 0;
}
