#include <stdio.h>
#include <math.h>

int che[450][450] = {0};
int arr[200010] = {0};

int main(void){
    int n, q;
    scanf("%d %d", &n, &q);
    int sn = (int)sqrt((double)n);
    for(int i=0;i<q;i++){
        int t;
        scanf("%d", &t);
        if(t==1){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            if(b<sn){
                che[b][a] += c;
            }else{
                for(int j=a;j<=n;j+=b){
                    arr[j] += c;
                }
            }
        }else{
            int d, ans = 0;
            scanf("%d", &d);
            for(int j=1;j<sn;j++){
                ans += che[j][d%j];
            }
            ans += arr[d];
            printf("%d\n", ans);
        }
    }
    return 0;
}
