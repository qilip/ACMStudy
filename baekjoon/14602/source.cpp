#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(void){
    int m, n, k, w, mn[310][310];
    scanf("%d %d %d %d", &m, &n, &k, &w);
    for(int q=0;q<m;q++){
        for(int p=0;p<n;p++){
            scanf("%d", &mn[q][p]);
        }
    }
    for(int i=w/2;i<m-(w/2);i++){
        for(int j=w/2;j<n-(w/2);j++){
            int arr[310], cnt = 0;
            for(int x=i-w/2;x<=i+w/2;x++){
                for(int y=j-w/2;y<=j+w/2;y++){
                    arr[cnt] = mn[x][y];
                    cnt++;
                }
            }
            sort(arr, arr+cnt);
            printf("%d ", arr[cnt/2]);
        }
        printf("\n");
    }
    return 0;
}
