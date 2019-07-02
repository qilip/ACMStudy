#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265358979

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout<<setprecision(12)<<fixed;

	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		long double ans = 0;
        int r, s, e;
        cin >> r >> s >> e;
		int n;
		cin >> n;
		double cur = s;
		for(int i=0;i<n;i++){
			int nl, nr, nh;
			cin >> nl >> nr >> nh;
			if(nh>=r){
				ans += (nl-r) - cur;
				cur = (nr+r);
				ans += 2*(nh-r);
				ans += r*PI;
				ans += nr-nl;
			}else{
				double mit = sqrt(pow(r, 2)-pow(r-nh, 2));
				ans += (nl-mit) - cur;
				cur = nr+mit;
				ans += 2*r*acos((r-nh)/(double)r);
				ans += nr-nl;
			}
		}
		ans += e - cur;
		cout << "Case #" << test_case+1 << "\n" << ans << endl;
	}
	return 0;
}
