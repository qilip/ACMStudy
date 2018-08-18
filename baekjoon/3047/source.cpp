#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n[3];
    char s[4];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    scanf(" %s", s);
    sort(n, n+3);
    printf("%d %d %d", n[s[0]-'A'], n[s[1]-'A'], n[s[2]-'A']);
    return 0;
}
