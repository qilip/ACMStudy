#include <cstdio>
#include <queue>

using namespace std;

int n, nn[1010][1010];
queue<pair<int, int>> q[1010]; // 목적지, 간선 고유번호
int id; // 간선 고유번호
vector<int> visited;

void euc(int csr){
	while(1){
		while(!q[csr].empty() && visited[q[csr].front().second]) q[csr].pop();
		if(q[csr].empty()) break;
		auto [x, y] = q[csr].front();
		q[csr].pop();
        visited[y] = 1;
		euc(x);
    }
    printf("%d ", csr);
}

int main(void){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp) cnt+=tmp;
            nn[i][j] = tmp;
        }
        if(cnt%2){
            printf("-1");
            return 0;
        }
    }
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			while(nn[i][j]){
				nn[i][j]--;
				id++;
				q[i].push({j, id});
				q[j].push({i, id});
			}
		}
	}
	visited.resize(id + 1);
    euc(1);
    return 0;
}
