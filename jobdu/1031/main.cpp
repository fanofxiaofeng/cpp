#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int process(int n);

int main(){
    int n;

    while(true){
        cin >> n;
        if(n == 0)
            break;
        cout << process(n) << endl;
    }

    return 0;
}

int process(int n){
    int cnt = 0;
    while(n != 1){
        if(n % 2 == 0)
            n /= 2;
        else
            n = (3 * n + 1) / 2;
        cnt++;
    }

    return cnt;
}
