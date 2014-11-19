#include <iostream>
#include <vector>

using namespace std;

const int big = 50;

int matrix[big][big];
int nextRow(int, int);
int nextCol(int, int);

int main(){
    int n;
    cin >> n;
    int row = 0;
    int col = n - 1;
    int bound = 2 * n - 1 - 1;
    int total = (2 * n - 1) * (2 * n - 1);
    for(int i = 1;i <= total;i++){
        matrix[row][col] = i;
        int tempRow = nextRow(row, bound);
        int tempCol = nextCol(col, bound);
        if(matrix[tempRow][tempCol] != 0){
            row = nextCol(row, bound);
        } else {
            row = tempRow;
            col = tempCol;
        }
    }
    for(int r = 0;r <= bound;r++){
        for(int c = 0;c <= bound;c++)
            cout << matrix[r][c] << " ";
        cout << endl;
    }
    return 0;
}

int nextRow(int r, int bound){
    return (r == 0)?(bound):(r - 1);
}

int nextCol(int c, int bound){
    return (c == bound)?(0):(c + 1);
}
