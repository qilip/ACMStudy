#include <stdio.h>

int main(void){
    int s, ss;
    scanf("%d %d", &s ,&ss);
    while(s--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a!=b){
            printf("Wrong Answer");
            return 0;
        }
    }
    while(ss--){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a!=b){
            printf("Why Wrong!!!");
            return 0;
        }        
    }
    printf("Accepted");
    return 0;
}
