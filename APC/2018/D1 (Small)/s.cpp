#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

int nn[100005];
int counter[500010], last_dup = 0;
int packs[100005], packs_ptr = 0;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf(" %d", &nn[i]);
    }
    for(int i=1;i<=n;i++){
        if(!counter[nn[i]]){
            counter[nn[i]]+=i;
            if(i==n){
                packs[packs_ptr++] = i-last_dup;
            }
        }else{
            packs[packs_ptr++] = i-1-last_dup;
            int llast_dup = last_dup;
            if( last_dup < counter[nn[i]]) last_dup = counter[nn[i]];
            for(int j=llast_dup;j<last_dup;j++){
                counter[nn[j]] = 0;
            }
            counter[nn[i]] = i;
        }
    }
    sort(packs, packs+packs_ptr, greater<int>());
    printf("%d", packs[m-1]);
    return 0;
}
