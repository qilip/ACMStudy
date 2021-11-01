/***
 * ! 세그트리 + DP
 * ? 변경 지점마다 변경 부분에 대한 DP만 수행
 * ? 시간복잡도 : N*W*6*logP 유저*대역폭*화질수*log지점수(N*2)
 **/

#include <cstdio>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 510;
const int MAX_W = 5010;

int n, w; // n: 사람 수, w: 서버 대역폭
int qu[7]; // 화질별 대역폭 사용량
int happy[MAX_N][7]; // 유저 화질별 만족도

int pcnt; // 좌표 개수
int tree_n = 1; // pcnt <= 인 2^x , 리프노드 개수
vector<pair<int, int>> vn; // 원본 (지점, 유저번호)
pair<int, int> vp[MAX_N]; // 압축 [유저번호](시작, 끝)
map<int, int> com_p; // 좌표압축 원본 -> 결과
int ori_p[MAX_N*2]; // 좌표압축 결과 -> 원본

// 트리에는 좌표압축된 결과를 사용
// 좌표압축시 동일 원본좌표는 동일 압축좌표 가짐
// 1~pcnt개의 좌표
vector<int> ntree[MAX_N*5]; // 유저 구간 저장 트리
stack<vector<int>> dp; // DP 백업 스택
ll ans; // 총 만족도

// 포인트 좌표압축 1~ / map 없을 때 반환값 때문에
int comp_point(int ori){
    int cp = com_p[ori];
    if(cp) return cp;
    com_p[ori] = ++pcnt;
    ori_p[pcnt] = ori;
    return pcnt;
}

// 트리에 유저 구간 저장 [l, r] / 1 base
void init(int l, int r, int user){
    for(l+=tree_n-1, r+=tree_n-1; l<=r; l>>=1, r>>=1){
		if(l&1) ntree[l].push_back(user);
		if(~r&1) ntree[r].push_back(user);
		l++; r--;
	}
}

// 추가된 유저에 대해서만 DP
void diff_dp(int cur){
    for(int user : ntree[cur]){
        for(int i=w;i>=0;i--){ // 서버 대역폭 DP
            for(int j=1;j<=6;j++){ // 화질별로
                if(i+qu[j]<=w && dp.top()[i]>-1){
                    dp.top()[i+qu[j]] = max(dp.top()[i+qu[j]], dp.top()[i] + happy[user][j]);
                }
            }
        }
    }
}

// 트리 순회
void trav(int cur){
    // DP 스택 백업
    dp.push(dp.top());
    // DIFF DP 수행
    diff_dp(cur);
    if(tree_n <= cur){
        if(cur-tree_n+1 <= pcnt){
            // 리프노드, 만족도 계산 수행
            int cur_max = 0;
            for(int i=0;i<=w;i++){
                cur_max = max(cur_max, dp.top()[i]);
            }
            ans += (ll)cur_max * (ori_p[cur-tree_n+1] - ori_p[cur-tree_n]);
        }
    }else{
        trav(cur*2);
        trav(cur*2+1);
    }
    // 스택 복원
    dp.pop();
}

int main(void){
    // 입력
    scanf("%d %d", &n, &w);
    for(int i=1;i<=6;i++){
        scanf("%d", &qu[i]);
    }
    for(int i=1;i<=n;i++){
        int st, ed;
        scanf("%d %d", &st, &ed);
        vn.emplace_back(st, i);
        vn.emplace_back(ed, i);
        for(int j=1;j<=6;j++){
            scanf("%d", &happy[i][j]);
        }
    }
    // 좌표압축 & ntree build
    sort(vn.begin(), vn.end());
    for(auto cur : vn){
        auto [pt, usr] = cur;
        int npt = comp_point(pt);
        if(!vp[usr].first) vp[usr].first = npt;
        else vp[usr].second = npt;
    }
    int u_cnt = 0;
    // tree_n 계산
    while(tree_n<pcnt) tree_n *= 2;
    for(int i=1;i<=n;i++){
        // 원본은 (a,b] 느낌이라 시작지점 포함하면 계산 어려워짐
        // +1해서 [a,b] 로 바꿔서 계산 쉽게
        init(vp[i].first+1, vp[i].second, ++u_cnt);
    }

    // 트리 순회하며 변경 부분만 DP
    // 전위 순회 DFS 느낌
    // 리프 노드 탈출마다 정산 (현재 원본좌표 - 직전 원본좌표) * 현재 시청 만족도
    vector<int> dp_init(w+1);
    fill(dp_init.begin(), dp_init.end(), -1);
    dp_init[0] = 0;
    dp.push(dp_init);
    trav(1);

    printf("%lld", ans);
    return 0;
}
