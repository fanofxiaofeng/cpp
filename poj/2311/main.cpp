#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int big = 210;
const int enough = 500;

int mex[big][big];

void init(void);
void calc(int, int);

int main(){
    init();

    mex[2][2] = 0;
    mex[2][3] = 0;
    mex[3][2] = 0;

    for(int r = 2;r < big;r++){
        for(int c = 2;c < big;c++){
            if(mex[r][c] == -1){
                //printf("Line number: %d. r: %d, c: %d\n", __LINE__, r, c);
                calc(r, c);
                /*
                if(r == 2 && c < 20)
                    printf("[r:%d, c:%d]: %d\n", r, c, mex[r][c]);
                */
            }
        }
    }
    int r;
    int c;
    while(scanf("%d %d", &r, &c) == 2){
        if(mex[r][c] == 0)
            printf("LOSE\n");
        else
            printf("WIN\n");
    }

    return 0;
}

void calc(int row, int col){
    vector<bool> bvec(enough, false);
    for(int r = 2;2 * r <= row;r++)
        bvec[mex[r][col] ^ mex[row - r][col]] = true;
    for(int c = 2;2 * c <= col;c++)
        bvec[mex[row][c] ^ mex[row][col - c]] = true;
    int record = -1;
    for(int i = 0;;i++){
        if(bvec[i] == false){
            record = i;
            break;
        }
    }
    mex[row][col] = record;
    //printf("row: %d, col:%d, value: %d\n", row, col, mex[row][col]);
}

void init(void){
    for(int r = 0;r < big;r++){
        for(int c = 0;c < big;c++)
            mex[r][c] = -1;
    }
}
