#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main(void){
    int n;
	scanf("%d", &n);
	vector<pair<int ,int>> v;
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a>b) swap(a, b);
		v.emplace_back(b, a);
	}
	int d;
	scanf("%d", &d);
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<>> pq;
	int cnt_max = 0;
	for(auto &[ed, st] : v){
		pq.push(st);
		while(pq.size() && pq.top() < ed-d){
			pq.pop();
		}
		cnt_max = max(cnt_max, (int)pq.size());
	}
	printf("%d", cnt_max);
	return 0;	
}