#include <cstdio>
#include <algorithm>

int main(void) {
	int N, S = 0, a[50], b[50];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 0; i < N; i++) scanf("%d", &b[i]);
	std::sort(a, a + N);
	std::sort(b, b + N);
	for (int i = 0; i < N; i++) {
		S += a[N - 1 - i] * b[i];
	}
	printf("%d", S);
	return 0;
}
