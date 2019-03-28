#include <stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int max3(int a, int b, int c){
    int d = max(a, b);
    return max(c, d);
}

int min(int a, int b){
    return a > b ? b : a;
}

int min3(int a, int b, int c){
    int d = min(a, b);
    return min(c, d);
}

int main(void){
    int n;
    int a, b, c;
    int ldp[2][3] = {0};
    int sdp[2][3] = {0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &a, &b, &c);
        ldp[i%2][0] = max(ldp[(i+1)%2][1], ldp[(i+1)%2][0]) + a;
        ldp[i%2][1] = max3(ldp[(i+1)%2][2], ldp[(i+1)%2][1], ldp[(i+1)%2][0]) + b;
        ldp[i%2][2] = max(ldp[(i+1)%2][1], ldp[(i+1)%2][2]) + c;

        sdp[i%2][0] = min(sdp[(i+1)%2][1], sdp[(i+1)%2][0]) + a;
        sdp[i%2][1] = min3(sdp[(i+1)%2][2], sdp[(i+1)%2][1], sdp[(i+1)%2][0]) + b;
        sdp[i%2][2] = min(sdp[(i+1)%2][1], sdp[(i+1)%2][2]) + c;
    }
    int mm = max3(ldp[n%2][0], ldp[n%2][1], ldp[n%2][2]);
    int nn = min3(sdp[n%2][0], sdp[n%2][1], sdp[n%2][2]);
    printf("%d %d", mm, nn);
    return 0;
}
