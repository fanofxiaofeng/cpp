#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void f(vector<int> &, int, int);
void swap(vector<int> &, int, int);

int main(){
    int n;
    while(cin >> n){
        vector<int> ivec;
        for(int i = 0;i < n;i++){
            int temp;
            cin >> temp;
            ivec.push_back(temp);
        }

        f(ivec, 0, ivec.size() - 1);

        for(int i = 0;i < ivec.size();i++)
            cout << ivec[i] << " ";

        cout << endl;
    }

    return 0;
}

void f(vector<int> &ivec, int low, int high){// 快排的程序
    if(low >= high)
        return;

    int i = low - 1;
    for(int j = low;j < high;j++){
        if(ivec[j] < ivec[high])
            swap(ivec, ++i, j);
    }

    swap(ivec, i + 1, high);

    f(ivec, low, i);
    f(ivec, i + 2, high);
}

void swap(vector<int> &ivec, int i, int j){
    int temp = ivec[i];
    ivec[i] = ivec[j];
    ivec[j] = temp;
}
