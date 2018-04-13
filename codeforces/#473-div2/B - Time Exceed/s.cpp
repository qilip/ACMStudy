#include <stdio.h>
#include <iostream>
#include <string.h>

char nn[100010][30];
int ns[100010];
int kk[100010];
char mm[100010][30];

int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k, m, i, j;
    scanf("%d %d %d", &n, &k, &m);

    for(i=0;i<n;i++) scanf("%s", nn[i]);
    for(i=0;i<n;i++) scanf("%d", &ns[i]);
    for(i=0;i<k;i++) {
        int words, min = 1000000001;
        scanf("%d", &words);
        for(j=0;j<words;j++){
            scanf("%d", &kk[j]);
            if(min > ns[ kk[j]-1 ]) min = ns[ kk[j]-1 ];
        }
        for(j=0;j<words;j++){
            ns [ kk[j]-1 ] = min;
        }
    }
    int ptr = 0;
    long long cnt = 0;
    for(i=0;i<m;i++) {
        scanf("%s", mm[i]);
        A:;
        if(ptr == n) ptr = 0;
        if( !strcmp(nn[ptr], mm[i]) ){
            cnt += ns[ptr];
            ptr++;
        }else{
            ptr++;
            goto A;
        }
    }
    std::cout << cnt;
}
