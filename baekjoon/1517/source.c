#include <stdio.h>

int n, a[500001], tmp[500001];
long long ans;

void msort(int s, int m, int d){
    for(int i=s;i<=d;i++)
        tmp[i] = a[i];
    int left = s;
    int right = m+1;
    int cur = s;
    while(left<=m && right<=d){
        if(tmp[left] <= tmp[right]){
            a[cur++] = tmp[left++];
        }else{
            a[cur++] = tmp[right++];
            ans += right-cur;
        }
    }
    int r = m - left;
    for(int i=0;i<=r;i++){
        a[cur++] = tmp[left++];
    }
}

void merge(int s, int d){
    if(s==d) return;
    int m = (s+d)/2;
    merge(s, m);
    merge(m+1, d);
    msort(s, m, d);
}

int main(void){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    merge(0, n-1);
    printf("%lld", ans);
    return 0;
}
