#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d:\n", n);
    for(int i=2;i<=(n+1)/2;i++){
        int nn = n;
        int bol = 1;
        int cur1 = 1;
        while(nn){
            int a = 0;
            if(bol){
                a = 0; bol = 0;
            }else{
                a = 1; bol = 1;
            }
            if(nn>=i-a){
                nn -= (i-a);
            }else{
                cur1 = 0;
                break;
            }
        }
        if(cur1) printf("%d,%d\n", i, i-1);
        nn = n;
        int cur2 = 1;
        while(nn){
            if(nn>=i){
                nn -= i;
            }else{
                cur2 = 0;
                break;
            }
        }
        if(cur2) printf("%d,%d\n", i, i);
    }
    return 0;
}
