#include <stdio.h>
#include <algorithm>

int main(void){
    int a, b, c, cnt[100] = {0};
    scanf("%d %d %d", &a, &b, &c);
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                cnt[i+j+k]++;
    printf("%d", std::max_element(cnt, cnt+99) - cnt);
    return 0;
}
