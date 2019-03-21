#include <stdio.h>

int n, l;
int cur = 1;

int chk(int num){
    while(num){
        if(num%10 == l) return 1;
        num /= 10;
    }
    return 0;
}

int main(void){
    scanf("%d %d", &n, &l);
    while(n){
        if(!chk(cur)) n--;
        cur++;
    }
    printf("%d", cur-1);
    return 0;
}
