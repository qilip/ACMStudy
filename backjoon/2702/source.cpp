#include <cstdio>
#include <numeric>
// C++ 17

int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %d\n", std::lcm(a, b), std::gcd(a, b));
    }
}
