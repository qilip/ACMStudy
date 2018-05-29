#include <stdio.h>
#include <algorithm>

using namespace std;

double nn[100005] = {0};

int main(void){
    int n = 0, k = 0;
    scanf(" %d %d", &n, &k);
    for(int i=0;i<n;i++){
        int pi = 0;
        scanf(" %d", &pi);
        for(int j=0;j<pi;j++){
            double x = 0.0, y = 0.0;
            scanf(" %lf %lf", &x, &y);
            if ( x*x+y*y > nn[i] ) nn[i] = x*x+y*y;
        }
    }
    sort(nn, nn+n);
    printf("%0.2lf", nn[k-1]);
    return 0;
}
