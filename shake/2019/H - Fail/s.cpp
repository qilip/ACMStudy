#include <stdio.h>

typedef long long ll;

int n, c;
int x[25'0010];
int lr[25'0010];
int rl[25'0010];

int main(void){
    scanf("%d %d", &n, &c);
    for(int i=0;i<n;i++){
        scanf("%d", &x[i]);
    }
    for(int i=1;i<n;i++){
        lr[i] = lr[i-1] + (x[i] < x[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rl[i] = rl[i+1] + (x[i] < x[i+1]);
    }
    int mini = -1;
    ll minc = (0xFFFF'FFFF'FFFF'FFFF/2);
    for(int i=0;i<n;i++){
        //많이한쪽에다 적게한쪽 더할필요는 없네
        int d = (lr[n-1] - lr[i]) > (rl[0] - rl[i]) ? (lr[n-1] - lr[i]) : (rl[0] - rl[i]);
        ll ans = c*d - x[i];
        if(i!=0 && i!=n-1) ans += (x[0] > x[n-1] ? x[0] : x[n-1]);
        else{
            if(i==0) ans += x[n-1];
            else ans += x[0];
        }
        if(minc > ans){
            minc = ans;
            mini = i+1;
        }
    }
    printf("%d\n%lld", mini, minc);
    return 0;
}
