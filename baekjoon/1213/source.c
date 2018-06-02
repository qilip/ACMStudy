#include <stdio.h>

int main(void){
    int cnt[30] = {0};
    char inp[60] = {0};
    scanf("%s", inp);
    for(int i=0;inp[i]!='\0';i++){
        cnt[inp[i]-'A']++;
    }
    int odd = 0, odp = 0;
    for(int i=0;i<26;i++){
        if(cnt[i]%2){
            if(odd){
                printf("I'm Sorry Hansoo");
                return 0;
            }else{
                odd = 1;
                odp = i;
                cnt[i]--;
            }
        }
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<cnt[i]/2;j++){
            printf("%c", i+'A');
        }
    }
    for(int i=0;i<odd;i++){
        printf("%c", odp+'A');
    }
    for(int i=25;i>=0;i--){
        for(int j=0;j<cnt[i]/2;j++){
            printf("%c", i+'A');
        }
    }
    return 0;
}
