#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
    int i, j, cnt = 0;
    int inp[10];
    for(int q=0;q<9;q++){
        scanf("%d", &inp[q]);
        cnt += inp[q];
    }
    cnt -= 100;
    sort(inp, inp+9);
    for(i=0;i<9;i++){
        for(j=i+1;j<9;j++){
            if(cnt == inp[i] + inp[j]) goto E;
        }
    }
    E:;
    for(int k=0;k<9;k++){
        if(k!=i && k!=j) printf("%d\n", inp[k]);
    }
    return 0;
}
