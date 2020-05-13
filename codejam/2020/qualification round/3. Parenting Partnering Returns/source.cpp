#include <cstdio>
#include <algorithm>
#include <tuple>
#include <utility>

using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
        int n;
        tuple<int, int, int> se[1010];
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            int s, e;
            scanf("%d %d", &s, &e);
            se[i] = {s, e, i};
        }
        sort(se, se+n);
        char ans[1100] = {0};
        int c_end = 0;
        int j_end = 0;
        int imp = 0;
        for(int i=0; i<n; i++){
            if(c_end <= get<0>(se[i])){
                ans[get<2>(se[i])] = 'C';
                c_end = get<1>(se[i]);
            }else if(j_end <= get<0>(se[i])){
                ans[get<2>(se[i])] = 'J';
                j_end = get<1>(se[i]);
            }else{
                imp = 1;
            }
        }
        printf("Case #%d: ", t);
        if(imp) printf("IMPOSSIBLE\n");
        else printf("%s\n", ans);
    }
    return 0;
}
