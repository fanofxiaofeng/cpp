#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long int process(unsigned long long int);

int main(){
    unsigned long long int query;
    while(cin >> query)
        cout << process(query) << endl;

    return 0;
}

unsigned long long int process(unsigned long long int n){
    if(n == 0 || n == 1)
        return 1;
    return n * process(n - 1);
}
