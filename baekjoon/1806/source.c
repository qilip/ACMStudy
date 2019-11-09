#include <stdio.h>

int main(void){
    int n, s;
    int nn[100010] = {0};
    scanf("%d %d", &n, &s);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
    }
    int sum = 0;
    int min = 999999;
    int pl = 0;
    for(int pr=0;pr<n;pr++){
        sum += nn[pr];
        while(sum >= s && pl <= pr){
            if(min > pr-pl+1) min = pr-pl+1;
            sum -= nn[pl];
            pl++;
        }
    }
    if(min != 999999) printf("%d", min);
    else printf("0");
    return 0;
}
