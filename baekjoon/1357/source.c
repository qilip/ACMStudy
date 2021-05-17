#include <stdio.h>

int revint(char a[]){
    int r = 0;
    for(int i=0; i<4; i++){
        r *= 10;
        if(!a[3-i]) continue;
        r += a[3-i] - '0';
    }
    return r;
}

int main(void){
    char a[5] = { 0 }, b[5] = { 0 };
    scanf(" %s %s", a, b);
    int rev_result = revint(a) + revint(b);
    int r = 0;
    for(int i=0; i<4 && rev_result; i++){
        r *= 10;
        r += rev_result % 10;
        rev_result /= 10;
    }
    printf("%d", r);
    return 0;
}
