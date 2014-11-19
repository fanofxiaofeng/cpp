/*
ID: jyjz2001
TASK: numtri
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    ifstream f("numtri.in");

    int r;
    f >> r;

    vector<vector<int> > num;
    for(int i = 1;i <= r;i++){
        vector<int> row;
        int temp;
        for(int j = 1;j <= i;j++){
            f >> temp;
            row.push_back(temp);
        }
        num.push_back(row);
    }

    for(int i = r - 1;i >= 1;i--){
        int row = i - 1;
        for(int col = 0; col <= row;col++)
            num[row][col] += (num[row + 1][col] >= num[row + 1][col + 1])?num[row + 1][col]:num[row + 1][col + 1];
    }

    ofstream of("numtri.out");
    of << num[0][0] << endl;

    f.close();
    of.close();

    return 0;
}
