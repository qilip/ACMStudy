// #include <bits/stdc++.h>

/* codeforces printf %Lf problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <tuple>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <list>

using namespace std;

typedef long long ll;

int n, q;
vector<int> v[200010];
int tptr[200010];
int tree[200010];
int child[200010];
int ptr = 0;

int tr(int a){
    tptr[a] = ptr;
    tree[ptr++] = a;
    child[a] = 1;
    for(auto i : v[a]){
        child[a] += tr(i);
    }
    return child[a];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  // cout.tie(NULL); // SLOW?
    cout<<setprecision(8)<<fixed;
    // code start

    scanf("%d %d", &n, &q);

    for(int i=2;i<=n;i++){
        int a;
        scanf("%d", &a);
        v[a].push_back(i);
    }

    child[1] = tr(1);

    for(int i=0;i<q;i++){
        int u, k;
        scanf("%d %d", &u, &k);
        if(child[u] < k) printf("-1\n");
        else printf("%d\n", tree[tptr[u]+k-1]);
    }
    
    return 0;
}
