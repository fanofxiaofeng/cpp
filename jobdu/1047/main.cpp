#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void process(int);

int main(){
    int n;

    while(cin >> n){
        process(n);
    }

    return 0;
}

void process(int a){
    if(a <= 1){
        cout << "no" << endl;
        return;
    }

    for(int i = 2;i * i <= a;i++){
        if(a % i == 0){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}
