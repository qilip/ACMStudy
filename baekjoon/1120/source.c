#include <stdio.h>
#include <string.h>

int main(void){
    char a[54], b[54];
    int lena, lenb, lenm, cnt=51;
    scanf("%s %s", a, b);
    lena = strlen(a);
    lenb = strlen(b);
    lenm = lenb - lena;
    for(int i=0; i<=lenm;i++){
        int k = i;
        int tcnt = 0;
        for(int j=0;j<lena;j++){
            if(a[j]!=b[k]) tcnt++;
            k++;
        }
        if(tcnt<cnt) cnt = tcnt;
    }
    printf("%d", cnt);
}
