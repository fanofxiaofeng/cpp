/*
ID: jyjz2001
TASK: money
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
    ifstream fin("money.in");
    ofstream fout("money.out");

    int v;
    int n;

    fin >> v >> n;

    vector<int> money(v + 1);
    for(int i = 1;i <= v;i++)
        fin >> money[i];

    vector<long long> row(v + 1, 0);
    vector<vector<long long> > table(n + 1, row);

    for(int r = 0;r <= n;r++)// 如果可以只用第一种面值构造出,则值为1,否则为0
        table[r][1] = (r % money[1] == 0)?(1):(0);

    for(int c = 1;c <= v;c++)
        table[0][c] = 1;

    for(int c = 2;c <= v;c++){
        for(int r = 1;r <= n;r++){
            table[r][c] += (r >= money[c])?(table[r - money[c]][c]):(0);
            table[r][c] += table[r][c - 1];
        }
    }
    fout << table[n][v] << endl;

    fin.close();
    fout.close();

    return 0;
}
