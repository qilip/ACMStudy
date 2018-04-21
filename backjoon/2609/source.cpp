#include <cstdio>
#include <numeric>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d", std::gcd(a, b), std::lcm(a, b));
    return 0;
}
