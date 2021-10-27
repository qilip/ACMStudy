#include <bits/stdc++.h>

using namespace std;

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int an[110] = {0};
        char bn[110] = {0};
        int cn[110] = {0};
        for(int i=1;i<=n;i++){
            scanf("%1d", &an[i]);
        }
        an[0] = 1;
        an[n+1] = 1;
        scanf(" %s", bn+1);
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(bn[i] == '*') cn[i-1]++, cn[i]++, cn[i+1]++;
        }
        for(int k=1;k<=2;k++){
            int a[110] = {0};
            char b[110] = {0};
            int c[110] = {0};
            int ns = 0;
            for(int i=0;i<=n+1;i++){
                a[i] = an[i];
                b[i] = bn[i];
                c[i] = cn[i];
            }
            for(int i=k;i<=n;i++){
                if(b[i] != '*' && c[i-1] < a[i-1] && c[i] < a[i]) b[i] = '*', c[i]++, c[i+1]++;
                if(c[i] < a[i]) b[i+1] = '*', c[i]++, c[i+1]++, c[i+2]++;
                if(c[i] > a[i]){
                    ns -= 999;
                    break;
                }
            }
            for(int i=1;i<=n;i++){
                if(b[i] == '*') ns++;
            }
            if(ans < ns) ans = ns;
        }
        printf("%d\n", ans);
    }
    return 0;
}
