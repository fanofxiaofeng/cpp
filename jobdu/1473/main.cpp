#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void process(int);

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        process(temp);
    }

    return 0;
}

void process(int a){
    if(a == 0){
        cout << a << endl;
        return;
    }
    vector<int> ivec;
    while(a != 0){
        int temp = a % 2;
        ivec.push_back(temp);
        a /= 2;
    }

    while(ivec.size() != 0){
        cout << ivec[ivec.size() - 1];
        ivec.pop_back();
    }
    cout << endl;
}
