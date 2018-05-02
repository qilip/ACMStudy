#include <stdio.h>
#include <string.h>

char in[333335];

int main(void) {
    char first[8][4] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    char bin[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    scanf("%s", in);
    int len = strlen(in);
    int s = (int)in[0] - 48;
    printf("%s", first[s]);
    for(int i=1;i<len;i++){
        int t = (int)in[i] - 48;
        printf("%s", bin[t]);
    }
}
