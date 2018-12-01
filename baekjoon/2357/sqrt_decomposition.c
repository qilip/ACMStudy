#include <stdio.h>
#include <memory.h>
#include <math.h>

int nn[100010];
int mx[100010];
int mn[100010];

int main(void){
    int n, m;
    memset(mn, 0x3f, sizeof mn);
    scanf("%d %d", &n, &m);
    int sn = (int)sqrt((double)n);
    for(int i=0;i<n;i++){
        scanf("%d", &nn[i]);
        if(mx[i/sn]<nn[i]) mx[i/sn] = nn[i];
        if(mn[i/sn]>nn[i]) mn[i/sn] = nn[i];
    }
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        int am = 0, an = 1060000000;
        while(a%sn && a<=b){
            if(am<nn[a]) am = nn[a];
            if(an>nn[a]) an = nn[a];
            a++;
        }
        while((b+1)%sn && a<=b){
            if(am<nn[b]) am = nn[b];
            if(an>nn[b]) an = nn[b];
            b--;
        }
        while(a<=b){
            if(am<mx[a/sn]) am = mx[a/sn];
            if(an>mn[a/sn]) an = mn[a/sn];
            a += sn;
        }
        printf("%d %d\n", an, am);
    }
    return 0;
}
