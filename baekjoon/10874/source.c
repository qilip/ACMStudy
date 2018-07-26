#include <stdio.h>

int main(void){
    int n, rig[110];
    scanf("%d", &n);
    for(int i=1;i<=10;i++){
        rig[i] = (i-1)%5+1;
    }
    for(int i=1;i<=n;i++){
        int flg = 1;
        for(int i=1;i<=10;i++){
            int t;
            scanf("%d", &t);
            if(t!=rig[i]) flg = 0;
        }
        if(flg) printf("%d\n", i);
    }
    return 0;
}
