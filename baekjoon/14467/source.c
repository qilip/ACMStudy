#include <stdio.h>

int main(void){
    int n, cow[11], cnt = 0;
    for(int i=0;i<11;i++) cow[i] = 2;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(cow[a]==2) cow[a] = b;
        else{
            if(cow[a]!=b){
                cnt++;
                cow[a] = b;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
