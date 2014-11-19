#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int, int);

int main(){
    int a;
    int b;
    while(cin >> a >> b)
        cout << gcd(a, b) << endl;

    return 0;
}

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
