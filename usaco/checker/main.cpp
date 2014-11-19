/*
ID: jyjz2001
TASK: checker
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int big = 20;

bool board[big];
bool rpc[2 * big];// row plus col
bool rmc[2 * big];// row minus col

int record[big];

void f(const int, const int);

int cnt = 0;

ifstream fin("checker.in");
ofstream fout("checker.out");

int main(){
    int n;

    fin >> n;
    // cin >> n;

    f(0, n);

    fout << cnt << endl;

    return 0;
}

void f(const int row, const int total){
    if(row == total){
        cnt++;
        // cout << cnt << endl;
        if(cnt <= 3){
            for(int col = 0;col < total;col++){
                if(col != 0)
                    fout << " " << (record[col] + 1);
                else
                    fout << (record[col] + 1);
            }
            fout << endl;
        }
    }

    // row != total
    for(int col = 0;col < total;col++){
        if(board[col] == false && rpc[row + col] == false && rmc[row - col + big] == 0){
            board[col] = true;
            rpc[row + col] = true;
            rmc[row - col + big] = true;
            record[row] = col;

            f(row + 1, total);

            board[col] = false;
            rpc[row + col] = false;
            rmc[row - col + big] = false;
        }
    }
}
