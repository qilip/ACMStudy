#include <stdio.h>

int yo(int i, int a){
    int arr[32], cnt;
    for(cnt=0;a>0;cnt++){
        arr[cnt] = a%i;
        a /= i;
    }
    for(int i=0;i<cnt/2;i++){
        if(arr[i] != arr[cnt-i-1]) return 1;
    }
    return 0;
}

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        int a;
        scanf("%d", &a);
        int flg = 0;
        for(int i=2;i<=64;i++){
            if(!yo(i, a)){
                flg = 1;
            }
        }
        printf("%d\n", flg);
    }
    return 0;
}
