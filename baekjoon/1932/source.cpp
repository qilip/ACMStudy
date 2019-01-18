#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    vector<int> inp[501];
    vector<int> sum[501];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        sum[i].resize(i+1);
        for(int j=0;j<=i;j++){
            int t;
            scanf("%d", &t);
            inp[i].push_back(t);
        }
    }
    sum[0][0] = inp[0][0];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<2;k++){
                if(sum[i+1][j+k] < sum[i][j] + inp[i+1][j+k])
                    sum[i+1][j+k] = sum[i][j] + inp[i+1][j+k];
            }
        }
    }
    printf("%d", *max_element(sum[n-1].begin(), sum[n-1].end()));
    return 0;
}
