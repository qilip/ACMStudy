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
        if(binary_search(nn.begin(), nn.end(), inp)) printf("1 ");
        else printf("0 ");
    }
}
