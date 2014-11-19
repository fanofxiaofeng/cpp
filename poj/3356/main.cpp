#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m;
    int n;
    string x;
    string y;
    while(cin >> m >> x >> n >> y){
        vector<vector<int> > data;
        vector<int> row(n + 1);
        for(int i = 0;i <= m;i++)
            data.push_back(row);
        for(int row = 0;row <= m;row++)
            data[row][0] = row;
        for(int col = 0;col <= n;col++)
            data[0][col] = col;
        for(int row = 1;row <= m;row++){
            for(int col = 1;col <= n;col++){
                if(x[row - 1] == y[col - 1])
                    data[row][col] = data[row - 1][col - 1];
                else
                    data[row][col] = min(min(data[row - 1][col], data[row][col - 1]), data[row - 1][col - 1]) + 1;
            }
        }

        cout << data[m][n] << endl;
    }
    return 0;
}
