#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

int rowDelta[] = {1, -1, 0, 0};
int colDelta[] = {0, 0, 1, -1};

char maze[40][90];
int len[40];

bool isValid(int, int, int);

void dfs(int, int, int);

int main(){
    int n;
    scanf("%d", &n);
    gets(maze[0]);
    for(int i = 0;i < n;i++){
        int line = 0;
        while(true){
            gets(maze[line]);
            len[line] = strlen(maze[line]);

            if(maze[line][0] == '_')
                break;
            line++;
        }

        int R = -1;
        int C = -1;

        for(int row = 0;row < line;row++){
            for(int col = 0;col < len[row];col++){
                if(maze[row][col] == '*'){
                    R = row;
                    C = col;
                    dfs(R, C, line);
                }
            }
        }

        for(int row = 0;row <= line;row++)
            puts(maze[row]);
    }
}

void dfs(int row, int col, int line){
    queue<int> rowQ;
    queue<int> colQ;
    rowQ.push(row);
    colQ.push(col);

    while(!rowQ.empty()){
        int R = rowQ.front();
        int C = colQ.front();
        rowQ.pop();
        colQ.pop();

        maze[R][C] = '#';
        for(int loop = 0;loop < 4;loop++){
            if(isValid(R + rowDelta[loop], C + colDelta[loop], line)){
                rowQ.push(R + rowDelta[loop]);
                colQ.push(C + colDelta[loop]);
            }
        }
    }
}

bool isValid(int row, int col, int line){
    if(row < 0 || row >= line)
        return false;
    if(col < 0 || col >= len[row])
        return false;
    return maze[row][col] == ' ';
}

