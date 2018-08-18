#include <stdio.h>

int arr[6][3];
int bar[6][3];
int ab[15][2];
int flg;

void bt(int dep){
    if(dep==15){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                if(bar[i][j] != arr[i][j]){
                    return;
                }
            }
        }
        flg = 1;
        return;
    }
    int a = ab[dep][0], b = ab[dep][1];
    bar[a][0]++; bar[b][2]++;
    bt(dep+1);
    bar[a][0]--; bar[b][2]--;
    bar[a][2]++; bar[b][0]++;
    bt(dep+1);
    bar[a][2]--; bar[b][0]--;
    bar[a][1]++; bar[b][1]++;
    bt(dep+1);
    bar[a][1]--; bar[b][1]--;
    return;
}

int main(void){
    for(int t=0;t<4;t++){
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                scanf("%d", &arr[i][j]);
            }
        }
        for(int i=0, k=0;i<5;i++){
            for(int j=i+1;j<6;j++){
                ab[k][0] = i;
                ab[k++][1] = j;
            }
        }
        bt(0);
        if(flg) printf("1 ");
        else printf("0 ");
        flg = 0;
    }
    return 0;
}
