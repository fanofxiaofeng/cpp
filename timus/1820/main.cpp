#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;

    if(k >= n){
        cout << "2" << endl;
    } else {
        cout << (2 * n / k + ((2 * n) % k != 0)) << endl;
    }


    return 0;
}
