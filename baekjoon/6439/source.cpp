#include <stdio.h>
#include <utility>

using namespace std;

typedef long long ll;

struct point{
    ll x, y;

    point operator - (const point &o) const{
        return { x-o.x, y-o.y };
    }
};

struct square{
    ll l, t, r, b;
};

struct line{
    point a, b;
};

square sq;
line li;
point tl, tr, bl, br;

int ccw(point a, point b, point c){
    b = b - a;
    c = c - a;
    ll ans = b.x*c.y - c.x*b.y;
    return ans > 0 ? 1 : (ans < 0 ? -1 : 0);
}

bool iner(){
    if( !(sq.l <= li.a.x && sq.l <= li.b.x) ) return false;
    if( !(sq.t >= li.a.y && sq.t >= li.b.y) ) return false;
    if( !(sq.r >= li.a.x && sq.r >= li.b.x) ) return false;
    if( !(sq.b <= li.a.y && sq.b <= li.b.y) ) return false;
    return true;
}
bool linr(){
    if( (sq.t==li.a.y || sq.b==li.a.y) && sq.l <= li.a.x && sq.r >= li.a.x ) return true;
    if( (sq.t==li.b.y || sq.b==li.b.y) && sq.l <= li.b.x && sq.r >= li.b.x ) return true;
    if( (sq.l==li.a.x || sq.r==li.a.x) && sq.t >= li.a.y && sq.b <= li.a.y ) return true;
    if( (sq.l==li.b.x || sq.r==li.b.x) && sq.t >= li.b.y && sq.b <= li.b.y ) return true;
    return false;
}

bool chk_ccw(){
    if( ccw(tl, tr, li.a)*ccw(tl, tr, li.b)==-1 && ccw(li.a, li.b, tl)*ccw(li.a, li.b, tr)!=1 ) return true;
    if( ccw(tr, br, li.a)*ccw(tr, br, li.b)==-1 && ccw(li.a, li.b, tr)*ccw(li.a, li.b, br)!=1 ) return true;
    if( ccw(bl, br, li.a)*ccw(bl, br, li.b)==-1 && ccw(li.a, li.b, bl)*ccw(li.a, li.b, br)!=1 ) return true;
    if( ccw(tl, bl, li.a)*ccw(tl, bl, li.b)==-1 && ccw(li.a, li.b, tl)*ccw(li.a, li.b, bl)!=1 ) return true;
    return false;
}

int main(void){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%lld %lld %lld %lld", &li.a.x, &li.a.y, &li.b.x, &li.b.y);
        scanf("%lld %lld %lld %lld", &sq.l, &sq.t, &sq.r, &sq.b);
        if(sq.l > sq.r) swap(sq.l, sq.r);
        if(sq.t < sq.b) swap(sq.t, sq.b);
        tl = {sq.l, sq.t};
        tr = {sq.r, sq.t};
        bl = {sq.l, sq.b};
        br = {sq.r, sq.b};
        if(iner() || linr() || chk_ccw()) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
