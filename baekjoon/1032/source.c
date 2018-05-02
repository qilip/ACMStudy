#include <stdio.h>
#include <string.h>

int main(void){
    int N;
    char inp[51][51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", inp[i]);
    int size = strlen(inp[0]);
    for (int i = 0; i < size ; i++) {
        char s = inp[0][i];
        int j = 0;
        for (j = 1; j < N ; j++) {
            if (s != inp[j][i]) break;
        }
        if (j==N) printf("%c", inp[0][i]);
        else printf("?");
    }
    return 0;
}
