#include <stdio.h>

int reverse(int a){
    int b = 0;
    while(a){
        b = (b * 10) + (a % 10);
        a /= 10;
    }
    return b;
}

int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int inp, inpr, res , resr;
        scanf("%d", &inp);
        inpr = reverse(inp);
        res = inp + inpr;
        resr = reverse(res);
        if(res == resr) printf("YES\n");
        else printf("NO\n");
    }
}
