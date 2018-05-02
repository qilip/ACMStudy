#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nn;

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        int inp;
        scanf("%d", &inp);
        nn.push_back(inp);
    }
    sort(nn.begin(), nn.end());
    int M;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int inp;
        scanf("%d", &inp);
        auto a = lower_bound(nn.begin(), nn.end(), inp);
        auto b = upper_bound(nn.begin(), nn.end(), inp);
        printf("%d ", b - a);
    }
}
