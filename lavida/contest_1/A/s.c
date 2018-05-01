#include <stdio.h>

int main(void){
    int x;
    scanf("%d", &x);
    if(x==100){
        printf("A++");
    }else if(x>=97){
        printf("A+");
    }else if(x>=93){
        printf("A");
    }else if(x>=90){
        printf("A-");
    }else if(x>=87){
        printf("B+");
    }else if(x>=83){
        printf("B");
    }else if(x>=80){
        printf("B-");
    }else if(x>=77){
        printf("C+");
    }else if(x>=73){
        printf("C");
    }else if(x>=70){
        printf("C-");
    }else if(x>=67){
        printf("D+");
    }else if(x>=63){
        printf("D");
    }else if(x>=60){
        printf("D-");
    }else{
        printf("F");
    }
    return 0;
}
