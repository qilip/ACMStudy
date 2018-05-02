#include <stdio.h>

int main(void){
    int a[9], flg = 0;
    for(int i=1;i<=8;i++){
        scanf("%d", &a[i]);
    }
    if(a[1] == 1){
        for(int i=2;i<=8;i++){
            if(a[i]!=i){
                flg = 2;
                break;
            }
        }
        if(flg == 0) printf("ascending");
    }
    else if(a[1]==8){
        for(int i=7;i>=0;i--){
            if(a[8-i]!=i+1){
                flg = 2;
                break;
            }
        }
        if(flg == 0) printf("descending");
    }
    else flg = 2;
    if(flg == 2) printf("mixed");
    return 0;
}
