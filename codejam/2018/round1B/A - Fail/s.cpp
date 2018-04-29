#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        int N, L, sum = 0, ans = 0;
        vector< pair<double, double> >v;
        scanf("%d %d", &N, &L);
        double one = 100.0/N;
        for(int i=0;i<L;i++){
            int votes;
            scanf("%d", &votes);
            sum += votes;
            double pcnt = (double)votes*one;
            double sml = pcnt-(int)pcnt;
            if(sml>0.49999){
                ans += (int)pcnt + 1;
            }else if(sml<0.00001){
                ans += (int)pcnt;
            }else{
                v.emplace_back(sml, pcnt);
            }
        }
        sort(v.begin(), v.end());
        int vptr = v.size()-1, left = 0;
        for(int i=0; i<N-sum; i++){
            if(vptr<0){
                left = N-sum-i;
                break;
            }
            v[vptr].first += one-(int)one;
            v[vptr].second += one;
            if(v[vptr].first > 0.49999){
                ans += (int)(v[vptr].second) + 1;
                vptr--;
            }else if(v[vptr].first < 0.00001){
                ans += (int)v[vptr].second;
                vptr--;
            }
        }
        for(int i=vptr;i>=0;i--){
            ans += (int)(v[i].second);
        }
        double tmp = 0;
        for(int i=0;i<left;i++){
            tmp += one;
            if(tmp-(int)tmp>0.49999){
                ans += (int)tmp+1;
                tmp = 0;
            }else if(tmp-(int)tmp<0.00001){
                ans += (int)tmp;
                tmp = 0;
            }
        }
        ans += (int)tmp;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
