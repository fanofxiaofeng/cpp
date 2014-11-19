#include <iostream>

using namespace std;

const int R = 30100;
const int C = 5;

unsigned long long int data[R][C];

int value[C] = {1, 5, 10, 25, 50};

void display(const unsigned long long int, const int);

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
        display(data[query][C - 1], query);

    return 0;
}

void display(const unsigned long long int way, const int target){
    if(way == 1)
        cout << "There is only 1 way";
    else
        cout << "There are " << way << " ways";

    cout << " to produce " << target << " cents change." << endl;
}
