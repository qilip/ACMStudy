#include <stdio.h>

struct point{
    int x, y;
    point operator- (const point &o) const{
        return {x - o.x, y - o.y};
    }
};

int ccw(point a, point b, point c){
    b = b - a;
    c = c - a;
    return b.x*c.y - c.x*b.y;
}

int main(void){
    point p[3];
    for(int i=0;i<3;i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    int ans = ccw(p[0], p[1], p[2]);
    printf("%d", ans > 0 ? 1 : (ans < 0 ? -1 : 0));
    return 0;
}
