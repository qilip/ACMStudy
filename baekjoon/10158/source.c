#include <stdio.h>

int main(void){
    int w, h, p, q, t;
    scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);
    int nowx = p, nowy = q, nxtx = 1, nxty = 1, cnt = 0, flg = 0;
    for(int i=0;i<t;i++){
        if(nowx == w || nowx == 0) nxtx *= -1;
        if(nowy == h || nowy == 0) nxty *= -1;
        nowx += nxtx; nowy += nxty;
        cnt++;
        if(nowx == p && nowy == q && nxtx == 1 && nxty == 1) { flg = 1; break; }
    }
    if(!flg) printf("%d %d", nowx, nowy);
    else {
        int tmp = t%cnt;
        nowx = p, nowy = q, nxtx = 1, nxty = 1;
        for(int i=0;i<tmp;i++){
            if(nowx == w || nowx == 0) nxtx *= -1;
            if(nowy == h || nowy == 0) nxty *= -1;
            nowx += nxtx; nowy += nxty;
        }
        printf("%d %d", nowx, nowy);
    }
    return 0;
}
