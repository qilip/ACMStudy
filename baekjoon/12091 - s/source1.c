#include <stdio.h>
#include <time.h>

int main(void){
    char evo[4][20] = { "", "Vaporeon", "Jolteon", "Flareon" };
    int s;
    scanf("%d", &s);
    clock_t ft, lt;
    double pt;
    ft = clock();
    while(1){
        lt = clock();
        pt = ( (double)(lt - ft) ) / CLOCKS_PER_SEC;
        if(pt>1.0) break;
    }
    printf("%s", evo[(time(NULL)+s)%3+1]);
}
