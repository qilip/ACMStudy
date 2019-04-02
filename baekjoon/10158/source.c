#include <stdio.h>

int main(void){
    int w, h, p, q, t;
    scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);
    int a = w - ((w - (p + t) % (w * 2)) > 0 ? (w - (p + t) % (w * 2)) : -(w - (p + t) % (w * 2)));
    int b = h - ((h - (q + t) % (h * 2)) > 0 ? (h - (q + t) % (h * 2)) : -(h - (q + t) % (h * 2)));
    printf("%d %d", a, b);
    return 0;
}
