#include <iostream>

using namespace std;

typedef long long ll;

int nn[1000010] = {0};
ll an[1000010] = {0};

int r(int c){
    if(nn[c] || c == 1) return nn[c];
    if(c%2) return nn[c] = r(c+1) + 1;
    else return nn[c] = r(c/2) + 1;
}

int main(void)
{
    for(int i=2;i<=1000000;i++)
        if(!nn[i]) r(i);
    for(int i=2;i<=1000000;i++)
        an[i] = an[i-1] + nn[i];

    // setbuf(stdout, NULL);
	int T, test_case;
    int a, b;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> a >> b;
		cout << "Case #" << test_case+1 << "\n" << an[b] - an[a-1] << endl;
	}

	return 0;
}
