#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void){
    double v[7];
    double d[7] = {0, 1, 2, 3, 4, 5, 6};
    for(int i=1;i<=6;i++){
        scanf("%lf", &v[i]);
    }
    double min = LONG_MAX;
    for(int i=1;i<=6;i++){
        double sum = 0;
        for(int j=1;j<=6;j++){
            if(i==j) continue;
            sum += v[j]*d[j];
        }
        double a = fabs((3.5-sum)/v[i]-d[i]);
        if(min>a) min = a;
    }
    printf("%0.3lf", min);
    return 0;
}
