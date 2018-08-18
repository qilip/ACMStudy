#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int a, b, c, d, e, f, sum = 0;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    sum = a + b + c + d - min(min(a, b), min(c, d)) + max(e, f);
    printf("%d", sum);
    return 0;
}
