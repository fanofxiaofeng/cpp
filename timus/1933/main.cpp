#include <stdio.h>

const int big = 210;

int mat[big][big];

void showData(int);

int main(){
    int n;
    scanf("%d", &n);

    int total = 2 * n + 1;

    for(int row = 0;row < total;row++){
        int label = row + 1;
        for(int delta = 1;delta <= n;delta++){
            int a = (row + total - delta) % total;
            int b = (row + total + delta) % total;
            // printf("a: %d, b: %d\n", a, b);
            mat[a][b] = label;
            mat[b][a] = label;
        }
    }

    showData(total);

    return 0;
}

void showData(int total){
    for(int row = 0;row < total;row++){
        for(int col = 0;col < total;col++){
            if(col != 0)
                putchar(' ');
            printf("%d", mat[row][col]);
        }
        putchar('\n');
    }
}
