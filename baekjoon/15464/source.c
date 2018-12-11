#include <stdio.h>

int main(void){
    int n;
    int go[110];
    int arr[4][110];
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d", &a);
        go[a] = i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &arr[0][i]);
    }
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++){
            arr[i+1][go[j]] = arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n", arr[3][i]);
    }
    return 0;
}
