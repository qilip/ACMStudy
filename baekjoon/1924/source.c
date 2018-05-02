#include <stdio.h>

int main(void) {
    int x, y, tmp, mth[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
    scanf("%d %d", &x, &y);
    y--;
    x--;
    while(x){
        x--;
        y+=mth[x];
    }
    
    tmp = y%7;
    switch(tmp) {
        case 0: { printf("MON"); break; }
        case 1: { printf("TUE"); break; }
        case 2: { printf("WED"); break; }
        case 3: { printf("THU"); break; }
        case 4: { printf("FRI"); break; }
        case 5: { printf("SAT"); break; }
        case 6: { printf("SUN"); break; }
    }
    return 0;
}
