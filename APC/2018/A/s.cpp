#include <stdio.h>

typedef long long ll;

int main(void){
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    for(int i=0;i<s1;i++){
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        if(tmp1 != tmp2){
            printf("Wrong Answer");
            return 0;
        }
    }
    for(int i=0;i<s2;i++){
        int tmp1, tmp2;
        scanf("%d %d", &tmp1, &tmp2);
        if(tmp1 != tmp2){
            printf("Why Wrong!!!");
            return 0;
        }
    }
    printf("Accepted");
    return 0;
}
