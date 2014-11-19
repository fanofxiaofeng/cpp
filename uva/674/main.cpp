#include <iostream>

using namespace std;

const int R = 7490;
const int C = 5;

unsigned int data[R][C];

int value[C] = {1, 5, 10, 25, 50};

int main(){
    for(int col = 0;col < C;col++)
        data[0][col] = 1;
    for(int row = 0;row < R;row++)
        data[row][0] = 1;

    for(int row = 1;row < R;row++){
        for(int col = 1;col < C;col++){
            for(int remain = row;remain >= 0;remain -= value[col])
                data[row][col] += data[remain][col - 1];
        }
    }

    int query;
    while(cin >> query)
        cout << data[query][4] << endl;

    return 0;
}
