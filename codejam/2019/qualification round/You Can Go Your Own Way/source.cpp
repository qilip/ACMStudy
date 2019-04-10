#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int n;
        char s[100010] = {0};
        char out[100010] = {0};
        scanf("%d", &n);
        scanf("%s", s);
        for(int i=0;i<2*n-2;i++){
            if(s[i] == 'S') out[i] = 'E';
            else out[i] = 'S';
        }
        printf("Case #%d: %s\n", t, out);
    }
    return 0;
}
