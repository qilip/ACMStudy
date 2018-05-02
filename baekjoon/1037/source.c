#include <stdio.h>

int main(void) {
    int nbr, inp, min = 1000000, max = 0;
    scanf("%d", &nbr);
    for(int i=0;i<nbr;i++) {
        scanf("%d", &inp);
        if(inp < min) min = inp;
        if(inp > max) max = inp;
    }
    printf("%d",min*max);
}
