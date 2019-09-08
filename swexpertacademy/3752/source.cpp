#include <stdio.h>

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("#%d ", t);
        int n;
        scanf("%d", &n);
        bool ar[10001] = {false};
        ar[0] = true;
        for(int i=0;i<n;i++){
            int c;
            scanf("%d", &c);
            for(int j=10000;j>=0;j--){
                if(ar[j]) ar[j+c] = true;
            }
        }
        int cnt = 0;
        for(int i=0;i<10001;i++){
            if(ar[i]) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
