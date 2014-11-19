#include <iostream>

using namespace std;

const int big = 30;

int table[big][big];

int main(){
    int m;
    int n;
    while(cin >> m >> n){
        for(int row = 0;row < m;row++){
            for(int col = 0;col < n;col++){
                cin >> table[row][col];
            }
        }

        for(int row = 0;row < m;row++){
            for(int col = 0;col < n;col++){
                int temp;
                cin >> temp;
                table[row][col] += temp;
            }
        }

        int cnt = 0;
        for(int row = 0;row < m;row++){
            int sum = 0;
            for(int col = 0;col < n;col++){
                sum += table[row][col];
            }
            if(sum == 0)
                cnt++;
        }

        for(int col = 0;col < n;col++){
            int sum = 0;
            for(int row = 0;row < m;row++){
                sum += table[row][col];
            }
            if(sum == 0)
                cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}
