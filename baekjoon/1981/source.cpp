#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int n, nn[120][120], g_max = 0, g_min = 201;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %d", &nn[i][j]);
            if(g_max < nn[i][j]) g_max = nn[i][j];
            if(g_min > nn[i][j]) g_min = nn[i][j];
        }
    }
    int left = abs(nn[1][1] - nn[n][n]), right = g_max-g_min, mid;
    int ans = g_max - g_min;
    while(left<=right){
        bool flg = false;
        mid = (left+right)/2;
        for(int min=g_min;min<=g_max-mid;min++){
            if( !(min<=nn[1][1] && nn[1][1]<=min+mid)||!(min<=nn[n][n] && nn[n][n]<=min+mid) ) continue;
            int arr[120][120] = {0};
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(min<=nn[i][j] && nn[i][j]<=min+mid) arr[i][j] = 1;
                }
            }
            queue<pair<int, int>> q;
            q.emplace(1, 1);
            int x = 1, y = 1;
            arr[1][1] = 0;
            int nx[] = {-1, 0, 1, 0}, ny[] = {0, 1, 0, -1};
            while( !q.empty() && !(x==n && y==n)){
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    if(arr[x+nx[i]][y+ny[i]]){
                        q.emplace(x+nx[i], y+ny[i]);
                        arr[x+nx[i]][y+ny[i]] = 0;
                    }
                }
            }
            if(x==n && y==n){
                flg = true;
                break;
            }
        }
        if(flg){
            right = mid-1;
            ans = mid;
        }else{
            left = mid+1;
        }
    }
    printf("%d", ans);
    return 0;
}
