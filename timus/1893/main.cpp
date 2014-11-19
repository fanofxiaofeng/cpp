#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    string str;
    cin >> str;
    int row = 0;
    char c;

    c = str[str.size() - 1];

    for(int i = 0;;i++){
        if(!(str[i] <= '9' && str[i] >= '0'))
            break;
        row = 10 * row + str[i] - '0';
    }

    // cout << row << endl;
    if(row <= 2){
        if(c == 'A' || c == 'D')
            cout << "window" << endl;
        else
            cout << "aisle" << endl;
    } else if(row <= 20){
        if(c == 'A' || c == 'F')
            cout << "window" << endl;
        else
            cout << "aisle" << endl;
    } else {
        if(c == 'A' || c == 'K')
            cout << "window" << endl;
        else if(c == 'C' || c == 'D' || c == 'G' || c == 'H')
            cout << "aisle" << endl;
        else
            cout << "neither" << endl;
    }

    return 0;
}

