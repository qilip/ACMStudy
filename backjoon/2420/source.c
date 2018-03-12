#include <stdio.h>
#include <stdlib.h>

int main(void) {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    printf("%lld", llabs(N-M));
    return 0;
}
