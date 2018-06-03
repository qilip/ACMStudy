#include <stdio.h>
#include <memory.h>

int n, m, nm[1010][1010];
int x[] = {-1, 0, 1, 0}, y[] = {0, 1, 0, -1};

void print(int a, int b){
    if(b==0){
        printf("%d ", a);
    }else if(a==n+1){
        printf("%d ", n+b);
    }else if(b==m+1){
        printf("%d ", n+m+n-a+1);
    }else{
        printf("%d ", n+n+m+m-b+1);
    }
}

void shot(int a, int b, int xy){
    while(1){
        a += x[xy]; b += y[xy];
        if(!nm[a][b]){
            print(a, b);
            break;
        }else if(nm[a][b]==2){
            switch(xy){
                case 0:{ xy = 1; break; }
                case 1:{ xy = 0; break; }
                case 2:{ xy = 3; break; }
                case 3:{ xy = 2; break; }
            }
        }
    }
}

int main(void){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tmp;
            scanf("%d", &tmp);
            nm[i][j] = tmp ? 2 : 1 ;
        }
    }
    for(int i=1;i<=n;i++) shot(i, 0, 1);
    for(int i=1;i<=m;i++) shot(n+1, i, 0);
    for(int i=n;i>=1;i--) shot(i, m+1, 3);
    for(int i=m;i>=1;i--) shot(0, i, 2);
    return 0;
}
