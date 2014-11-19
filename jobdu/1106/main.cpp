#include <iostream>
#include <cstdio>

using namespace std;

int f(int);

int main(){
    int n;
    while(cin >> n, n != 0)
        cout << f(n) << " " << f(n * n) << endl;

    return 0;
}

int f(int n){
    int sum = 0;
    while(n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
