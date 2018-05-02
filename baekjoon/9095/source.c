#include <stdio.h>

int asd(int a, int *p){
    if(a<0) return 0;
    else if(p[a]) return p[a];
    return p[a] = asd(a-3, p) + asd(a-2,p) + asd(a-1,p);
}

int main(void) {
    int T, p[11] = {0,1,2,4,0,0,0,0,0,0,0};
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int n, Q = 0;
        scanf("%d", &n);
        printf("%d", asd(n, p));
        if(i!=T-1) printf("\n");
    }
}
