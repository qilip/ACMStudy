#include <stdio.h>

typedef long long ll;

int n, nx[2010], ny[2010];
ll answer = 2100000000;

void re(int ptr_x, int ptr_y, int cha){
    if(ptr_y == n-1 && ptr_x == n-1){
        if( ptr_y==n-1 && ptr_x == n-1 && answer > cha) answer = cha;
        return;
    }else{
        if(ptr_x+1<n) re(ptr_x+1, ptr_y, cha+ ((ny[ptr_y]-nx[ptr_x+1])*(ny[ptr_y]-nx[ptr_x+1])) );
        if(ptr_y+1<n) re(ptr_x, ptr_y+1, cha+ ((ny[ptr_y+1]-nx[ptr_x])*(ny[ptr_y+1]-nx[ptr_x])) );
        if(ptr_x+1<n && ptr_y+1<n) re(ptr_x+1, ptr_y+1, cha+ ((ny[ptr_y+1]-nx[ptr_x+1])*(ny[ptr_y+1]-nx[ptr_x+1])) );
    }
}

int main(void){
    scanf(" %d", &n);
    for(int i=0;i<n;i++){
        scanf(" %d", &nx[i]);
    }
    for(int i=0;i<n;i++){
        scanf(" %d", &ny[i]);
    }
    re(0, 0, ((ny[0]-nx[0])*(ny[0]-nx[0])) );
    printf("%lld", answer);
    return 0;
}
