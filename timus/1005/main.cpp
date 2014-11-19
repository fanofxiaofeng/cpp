#include <iostream>
#include <vector>

using namespace std;

int opt;
int sum = 0;

void f(int, int, vector<int>&, vector<bool>&);

int main(){
    int n;
    cin >> n;
    vector<int> ivec;
    vector<bool> bvec;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        ivec.push_back(temp);
        bvec.push_back(true);
    }

    for(vector<int>::iterator it = ivec.begin();it != ivec.end();it++)
        sum += (*it);

    opt = sum;
    f(0, 0, ivec, bvec);
    cout << opt << endl;
    return 0;
}

void f(int pos, int acc, vector<int> &ivec, vector<bool> &bvec){
    if(pos == ivec.size()){
        int a = acc;
        int b = sum - acc;
        int temp = (a >= b)?(a - b):(b - a);
        if(temp < opt)
            opt = temp;
        return;
    }

    bvec[pos] = false;
    f(pos + 1, acc, ivec, bvec);

    bvec[pos] = true;
    f(pos + 1, acc + ivec[pos], ivec, bvec);
}
