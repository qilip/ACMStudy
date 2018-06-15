#include <stdio.h>

int main(n, q, k){
    char a[3][10] = { "Vaporeon", "Flareon", "Jolteon" };
    printf("%s", a[k%3]);
    return 0;
}
