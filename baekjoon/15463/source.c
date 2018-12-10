#include <stdio.h>

typedef struct {
    int x, y;
} dot;

dot s[3][2];
int ans;

int chkx(int a){
    if(s[a][0].x > s[2][0].x && s[2][1].x > s[a][1].x)
        return s[a][1].x - s[a][0].x;
    if(s[a][0].x < s[2][0].x && s[2][1].x < s[a][1].x)
        return s[2][1].x - s[2][0].x;
    if(s[a][0].x < s[2][0].x && s[2][0].x < s[a][1].x)
        return s[a][1].x - s[2][0].x;
    if(s[a][0].x < s[2][1].x && s[2][1].x < s[a][1].x)
        return s[2][1].x - s[a][0].x;
    return 0;
}

int chky(int a){
    if(s[a][0].y > s[2][0].y && s[2][1].y > s[a][1].y)
        return s[a][1].y - s[a][0].y;
    if(s[a][0].y < s[2][0].y && s[2][1].y < s[a][1].y)
        return s[2][1].y - s[2][0].y;
    if(s[a][0].y < s[2][0].y && s[2][0].y < s[a][1].y)
        return s[a][1].y - s[2][0].y;
    if(s[a][0].y < s[2][1].y && s[2][1].y < s[a][1].y)
        return s[2][1].y - s[a][0].y;
    return 0;
}

int check(int a){
    return chkx(a) * chky(a);
}

int main(void){
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++){
            int a, b;
            scanf("%d %d", &a, &b);
            s[i][j].x = a + 1010;
            s[i][j].y = b + 1010;
        }
    for(int i=0;i<2;i++)
        ans += (s[i][1].x-s[i][0].x)*(s[i][1].y-s[i][0].y);
    ans -= check(0) + check(1);
    printf("%d", ans);
    return 0;
}
