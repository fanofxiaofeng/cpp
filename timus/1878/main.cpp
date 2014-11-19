#include <stdio.h>

const int n = 4;

int num[n][n];

int main(){
    for(int r = 0;r < 4;r++){
        for(int c = 0;c < 4;c++)
            scanf("%d", &num[r][c]);
    }

    int opt = 8;
    for(int loop = 1;loop <= 4;loop++){
        int temp = 0;
        for(int r = 0;r < 2;r++){
            for(int c = 0;c < 2;c++){
                if(num[r][c] == loop)
                    continue;
                else if(num[n - 1 - r][n - 1 - c] == loop)
                    temp += 2;
                else
                    temp += 1;
            }
        }
        if(temp < opt)
            opt = temp;
    }

    printf("%d\n", opt);
    return 0;
}

