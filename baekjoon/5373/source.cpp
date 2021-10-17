#include <bits/stdc++.h>

using namespace std;

int cube[70];
int roi[8] = {1, 2, 3, 6, 9, 8, 7, 4};
int roo[6][12] = {
    {43, 42, 41, 33, 32, 31, 23, 22, 21, 13, 12, 11},
    {1, 4, 7, 21, 24, 27, 51, 54, 57, 49, 46, 43},
    {7, 8, 9, 31, 34, 37, 53, 52, 51, 19, 16, 13},
    {9, 6, 3, 41, 44, 47, 59, 56, 53, 29, 26, 23},
    {3, 2, 1, 11, 14, 17, 57, 58, 59, 39, 36, 33},
    {17, 18, 19, 27, 28, 29, 37, 38, 39, 47, 48, 49}
};
string str = "ULFRBD";

/* cube
 *            U 01 02 03
 *              04 05 06
 *              07 08 09
 * L 11 12 13 F 21 22 23 R 31 32 33 B 41 42 43
 *   14 15 16   24 25 26   34 35 36   44 45 46
 *   17 18 19   27 28 29   37 38 39   47 48 49
 *            D 51 52 53
 *              54 55 56
 *              57 58 59
 */

void init(){
    for(int i=1; i<60; i++)
        cube[i] = i;
}

void rotate(char a){
    int c = str.find(a);
    for(int i=0;i<2;i++)
        for(int j=0;j<7;j++)
            swap(cube[(c*10)+roi[j]], cube[(c*10)+roi[j+1]]);
    for(int i=0;i<3;i++)
        for(int j=0;j<11;j++)
            swap(cube[roo[c][j]], cube[roo[c][j+1]]);
}

void print(){
    for(int i=1; i<10; i++){
        printf("%c", "wgrboy"[cube[i]/10]);
        if(!(i%3)) printf("\n");
    }
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--){
        init();
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            char a, b;
            scanf(" %c%c", &a, &b);
            if(b == '-') rotate(a);
            else for(int j=0;j<3;j++) rotate(a);
            // printf("--t:%d/i:%d--\n", t, i);
            // print();
        }
        print();
    }
    return 0;
}
