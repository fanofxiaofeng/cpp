#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

vector<int> nwe;
vector<int> w;
vector<int> n;
vector<int> e;

void init(void);

int main(){
    init();
    int n;
    while(cin >> n)
        cout << nwe[n] << endl;

    return 0;
}

void init(void){
    nwe.push_back(0);
    w.push_back(0);
    n.push_back(0);
    e.push_back(0);

    nwe.push_back(3);
    w.push_back(1);
    n.push_back(1);
    e.push_back(1);

    for(int i = 2;i <= 20;i++){
        n.push_back(w[i - 1] + e[i - 1] + n[i - 1]);
        w.push_back(n[i - 1] + w[i - 1]);
        e.push_back(n[i - 1] + e[i - 1]);
        nwe.push_back(n[i] + w[i] + e[i]);
    }
}
