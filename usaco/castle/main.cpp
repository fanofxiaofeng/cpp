/*
ID: jyjz2001
TASK: castle
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <queue>

using namespace std;

const int big = 60;

const int west = 1;
const int north = 2;
const int east = 4;
const int south = 8;

const int num = 100;

int board[big][big];
int cc[big][big];// 记录所在连通分量
int cnt[big][big];

int w;// width
int h;// height

int getId(int, int);
int getRow(int);
int getCol(int);
void dfs(int, int, int);

int main(){

    ifstream fin("castle.in");
    ofstream fout("castle.out");

    fin >> w >> h;

    for(int row = 1;row <= h;row++){
        for(int col = 1;col <= w;col++){
            fin >> board[row][col];
        }
    }

    // 确定所属的连通分量
    for(int row = 1;row <= h;row++){
        for(int col = 1;col <= w;col++){
            if(cc[row][col] == 0)
                dfs(row, col, getId(row, col));
        }
    }

    int ccCounter = 0;
    int maxSeen = 0;
    for(int row = 1;row <= h;row++){
        for(int col = 1;col <= w;col++){
            // printf("%4d", cnt[row][col]);
            if(cnt[row][col] != 0){
                ccCounter++;
                if(cnt[row][col] > maxSeen)
                    maxSeen = cnt[row][col];
            }
        }
        // printf("\n");
    }

    fout << ccCounter << endl;
    fout << maxSeen << endl;

    int opt = 0;
    int rowRecord = -1;
    int colRecord = -1;
    char direction = '?';

    for(int col = 1;col <= w;col++){
        for(int row = h;row >= 1;row--){
            // 试图拆北墙
            if(row != 1 && ((board[row][col] & north) != 0)){
                if(cc[row][col] != cc[row - 1][col]){
                    int temp = cnt[getRow(cc[row][col])][getCol(cc[row][col])];
                    temp += cnt[getRow(cc[row - 1][col])][getCol(cc[row - 1][col])];
                    if(temp > opt){
                        opt = temp;
                        rowRecord = row;
                        colRecord = col;
                        direction = 'N';
                    }
                }
            }

            // 试图拆东墙
            if(col != w && ((board[row][col] & east) != 0)){
                if(cc[row][col] != cc[row][col + 1]){
                    int temp = cnt[getRow(cc[row][col])][getCol(cc[row][col])];
                    temp += cnt[getRow(cc[row][col + 1])][getCol(cc[row][col + 1])];
                    if(temp > opt){
                        opt = temp;
                        rowRecord = row;
                        colRecord = col;
                        direction = 'E';
                    }
                }
            }
        }
    }

    fout << opt << endl;
    fout << rowRecord << " " << colRecord << " " << direction << endl;
    fin.close();
    fout.close();

    return 0;
}

void dfs(int row, int col, int id){
    int R = getRow(id);
    int C = getCol(id);
    // printf("R is: %d, C is: %d\n", R, C);

    queue<int> rowQ;
    queue<int> colQ;
    rowQ.push(row);
    colQ.push(col);

    cc[row][col] = id;
    cnt[R][C]++;

    while(rowQ.empty() == false){
        int tempRow = rowQ.front();
        int tempCol = colQ.front();

        rowQ.pop();
        colQ.pop();

        // printf("cnt: %d\n", cnt[R][C]);
        // 西
        if((board[tempRow][tempCol] & west) == 0 && cc[tempRow][tempCol - 1] == 0){
            rowQ.push(tempRow);
            colQ.push(tempCol - 1);
            cc[tempRow][tempCol - 1] = id;
            cnt[R][C]++;
        }

        // 北
        if((board[tempRow][tempCol] & north) == 0 && cc[tempRow - 1][tempCol] == 0){
            rowQ.push(tempRow - 1);
            colQ.push(tempCol);
            cc[tempRow - 1][tempCol] = id;
            cnt[R][C]++;
        }

        // 东
        if((board[tempRow][tempCol] & east) == 0 && cc[tempRow][tempCol + 1] == 0){
            rowQ.push(tempRow);
            colQ.push(tempCol + 1);
            cc[tempRow][tempCol + 1] = id;
            cnt[R][C]++;
        }

        // 南
        if((board[tempRow][tempCol] & south) == 0 && cc[tempRow + 1][tempCol] == 0){
            rowQ.push(tempRow + 1);
            colQ.push(tempCol);
            cc[tempRow + 1][tempCol] = id;
            cnt[R][C]++;
        }
    }
}

int getRow(int id){
    return id / num;
}

int getCol(int id){
    return id % num;
}

int getId(int row, int col){
    return num * row + col;
}
