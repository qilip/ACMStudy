#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int t, n;
    scanf("%d %d", &t, &n);
    vector<int> cht;
    vector<int> ban;
    vector<int> player_pos(n+1, 1);
    vector<vector<int>> player_inv(n+1, vector<int>(54, 0));
    int a, b, d, e;
    char c;
    for(int i=0;i<t;i++){
        scanf("%d %d %c", &a, &b, &c);
        switch(c){
            case 'M':
                scanf("%d", &d);
                player_pos[b] = d;
            break;
            case 'F':
                scanf("%d", &d);
                if(player_pos[b] != d) cht.push_back(a);
                player_inv[b][d]++;
            break;
            case 'C':
                scanf("%d %d", &d, &e);
                if(!player_inv[b][d] || !player_inv[b][e]) cht.push_back(a);
                if(player_inv[b][d]) player_inv[b][d]--;
                if(player_inv[b][e]) player_inv[b][e]--;
            break;
            case 'A':
                scanf("%d", &d);
                if(player_pos[b] != player_pos[d]){
                    cht.push_back(a);
                    ban.push_back(b);
                }
            break;
        }
    }
    sort(cht.begin(), cht.end());
    sort(ban.begin(), ban.end());
    ban.erase(unique(ban.begin(), ban.end()), ban.end());
    printf("%d\n", (int)cht.size());
    for(int c : cht) printf("%d ", c);
    if(cht.size()) printf("\n");
    printf("%d\n", (int)ban.size());
    for(int c : ban) printf("%d ", c);
    if(ban.size()) printf("\n");
    return 0;
}
