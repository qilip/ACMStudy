#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);
    if(a%400==0) printf("1");
    else if(a%100==0) printf("0");
    else if(a%4==0) printf("1");
    else printf("0");
}
