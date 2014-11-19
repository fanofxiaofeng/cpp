#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0)
        cout << "1" << endl;
    else if(n > 0)
        cout << ((1 + n) * n / 2) << endl;
    else
        cout << ((1 + n) * (2 - n) / 2) << endl;
    return 0;
}
