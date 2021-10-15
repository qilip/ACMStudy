#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    int ans = arr[n-1] - arr[0];
    int crr[n-1];
    for(int i=1;i<n;i++){
        crr[i-1] = arr[i]-arr[i-1];
    }
    sort(crr, crr+n-1, greater<int>());
    for(int i=0;i<k-1&&i<n-1;i++){
        ans -= crr[i];
    }
    printf("%d\n", ans);
    return 0;
}
